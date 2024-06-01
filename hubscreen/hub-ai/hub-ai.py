from __future__ import print_function
import datetime
import os
import speech_recognition as sr
from gtts import gTTS
import paho.mqtt.client as mqtt
import playsound
import typedef_pb2
import threading
import time
import queue
import difflib

def find_closest_name(name, name_list, cutoff=0.6):
    if any(char.isdigit() for char in name):
        word_match = name.split()
        converted_match = ' '.join([num_to_word(word) if word.isdigit() else word for word in word_match])
        matches_recheck = difflib.get_close_matches(converted_match, name_list, n=1, cutoff=cutoff)
        if matches_recheck:
            return matches_recheck[0]
        return converted_match
    else:
        word_match = name.split()
        converted_match = ' '.join([word_to_num(word) if word.isalpha() else word for word in word_match])
        matches_recheck = difflib.get_close_matches(converted_match, name_list, n=1, cutoff=cutoff)
        if matches_recheck:
            return matches_recheck[0]
        return converted_match

def num_to_word(num):
    words = {"1": "one", "2": "two", "3": "three", "4": "four", "5": "five", "6": "six", "7": "seven", "8": "eight", "9": "nine", "10": "ten"}
    return words.get(num, num)

def word_to_num(word):
    words = {"one": "1", "two": "2", "three": "3", "four": "4", "five": "5", "six": "6", "seven": "7", "eight": "8", "nine": "9", "ten": "10"}
    return words.get(word, word)
    
language = "en"

def speak(text):
    print("HUB-AI: ",text)
    tts = gTTS(text=text, lang=language)
    filename = "voice.mp3"
    tts.save(filename)
    playsound.playsound(filename)


def get_audio():
    r = sr.Recognizer() 
    with sr.Microphone() as source:
        audio = r.listen(source)
        said = ""
        try:
            said = r.recognize_google(audio, language = language)
            print("USER: " ,said)
        except Exception as e:
            print("Exception: " + str(e))
    return said
                        
def get_time():
    now = datetime.datetime.now()
    current_time = now.strftime("%H:%M:%S")
    if language == "en":
        speak("Now is " + current_time)
    elif language == "vi":
        speak("bây giờ là " + current_time)



###### MQTT SETUP#########

data_queue = queue.Queue()
def on_connect(client, _, __, rc):
    print("Connected with return: ", rc)
    #Subscribe topic
    client.subscribe("hub/ai")

def on_message(_ , __, message):
    print("Recieved data from topic:", message.topic)
    _buff = typedef_pb2.Buffer()
    _buff.ParseFromString(message.payload)
    if _buff.receiver == typedef_pb2.User_t.Value("Ai"):
        print("<-- ", message.topic," : ",_buff)
        data_queue.put(_buff)

def mqtt_publish(topic, message):
    data = message.SerializeToString()
    client.publish(topic, data)
    print("--> ", topic," : ",message)

client = mqtt.Client(client_id="hub-ai") 
client.on_connect = on_connect
client.on_message = on_message

client.connect("127.0.0.1", 1883, 60)


buffer = typedef_pb2.Buffer()
device_names = []
def mqtt_thread():
    global buffer 
    global device_names
    while True:
        client.loop()
        if not data_queue.empty():
            temp = data_queue.get()
            if temp: 
                for led in temp.led:
                    buffer.led.append(led)
                    device_names.append(led.name)
                for sw in temp.sw:
                    buffer.sw.append(sw)
                    device_names.append(sw.name)
        time.sleep(0.1) 

mqtt_thread = threading.Thread(target=mqtt_thread)
mqtt_thread.daemon = True 
mqtt_thread.start()


def control_device(device_name, status): 
    device_name = text.lower().split("turn on")[1].strip()
    device_name = find_closest_name(device_name , buffer.led)
    if device_name in buffer.led:
        buff.led.clear()
        led = typedef_pb2.Led_t()
        led.name = device_name
        led.status = True
        buff.led.append(led)
        mqtt_publish("hub/ai", buff)
        speak(f"{device_name} is turned on")
    elif device_name in buffer.sw:
        buff.sw.clear()
        sw = typedef_pb2.Sw_t()
        sw.name = device_name
        sw.status = True
        buff.sw.append(sw)

        mqtt_publish("hub/ai", buff)
        speak(f"{device_name} is turned off")

check_system = True
buff = typedef_pb2.Buffer()
buff.sender = typedef_pb2.User_t.Ai
buff.receiver = typedef_pb2.User_t.Hub
buff.mac_hub = "8xff"
## handle ai
while True:
    if check_system == True:
        speak("The system is starting up")
        check_system = False 
    print("Listening")
    text = get_audio()
    if language == "en":

        if "who are" in text.lower():
            speak("I'm hub screen created by Living Lab, How can i help you")

        elif "hi" in text.lower() or "hello" in text.lower():
            speak("Hello")
            speak("How can i help you");

        elif "good morning" in text.lower():
            speak("Good morning sir")

        elif "thank you" in text.lower():
            speak("Thanks for giving me your time")

        elif "what time" in text.lower():
            get_time()
        
        elif "turn on" in text.lower():
            status = True
            device_name = text.lower().split("turn on")[1].strip()
            print("Device name: ",device_name)
            device_name = find_closest_name(device_name , device_names)
            for _led in buffer.led:
                if _led.name == device_name:
                    buff.led.clear()
                    buff.sw.clear()
                    led = typedef_pb2.Led_t()
                    led = _led
                    led.status = status
                    buff.led.append(led)
                    mqtt_publish("hub/ai", buff)
                    speak(f"{device_name} is turned on")
            for _sw in buffer.sw:    
                if _sw.name == device_name:
                    buff.sw.clear()
                    buff.led.clear()
                    sw = typedef_pb2.Sw_t()
                    sw = _sw
                    sw.name = device_name
                    sw.status = status
                    buff.sw.append(sw)
                    mqtt_publish("hub/ai", buff)
                    speak(f"{device_name} is turned on")

        elif "turn off" in text.lower():
            status = False
            device_name = text.lower().split("turn off")[1].strip()
            device_name = find_closest_name(device_name , device_names)
            for _led in buffer.led:
                if _led.name == device_name:
                    buff.sw.clear()
                    buff.led.clear()
                    led = typedef_pb2.Led_t()
                    led = _led
                    led.status = status
                    buff.led.append(led)
                    mqtt_publish("hub/ai", buff)
                    speak(f"{device_name} is turned off")
            for _sw in buffer.sw:    
                if _sw.name == device_name:
                    buff.sw.clear()
                    buff.led.clear()
                    sw = typedef_pb2.Sw_t()
                    sw = _sw
                    sw.name = device_name
                    sw.status = status
                    buff.sw.append(sw)
                    mqtt_publish("hub/ai", buff)
                    speak(f"{device_name} is turned off")

        elif "can you" in text.lower():
            if "speak" in text.lower():
                if "english" in text.lower() or "English" in text.lower():
                    speak("Yes I can speak English")
                elif "vietnamese" in text.lower() or "Vietnamese" in text.lower():
                    speak("Yes I can speak Vietnamese")

        elif "please" in text.lower() or "let" in text.lower():
            if "speak" in text.lower():
                if "vietnamese" in text.lower() or "Vietnamese" in text.lower():
                    speak("Yes i will speak vietnamese")
                    language = "vi"
                    speak("Tôi có thể giúp gì cho bạn")

        elif "good" in text.lower(): 
            speak("Thank you")

        # Thêm các case mới dưới đây
        elif "how are you" in text.lower():
            speak("I'm fine, thank you!")

        elif "love you" in text.lower():
            speak("I'm love you too")
        else:
            if len(text) > 0:
                speak("Sorry, I don't understand")
                speak("Please try again")

    elif language == "vi":

        if "bạn là ai" in text.lower():
            speak("Tôi tên là siri")
        
        elif "chào buổi sáng" in text.lower():
            speak("chào buổi sáng")

        elif "có thể" in text.lower():
            if "nói" in text.lower():
                if "tiếng anh" in text.lower():
                    speak("Có, tôi có thể nói tiếng Anh")
                elif "tiếng việt" in text.lower():
                    speak("Có, tôi có thể nói tiếng Việt")

        elif "hãy" in text.lower() or "làm ơn" in text.lower():
            if "nói tiếng" in text.lower():
                if "anh" in text.lower() or "Anh" in text.lower():
                    speak("Okay tôi sẽ nói tiếng anh")
                    language = "en";
                    speak("How can i help you");
        
        elif "đỉnh" in text.lower():
            if "thế" in text.lower():
                speak("Đương nhiên tôi đỉnh rồi")

        elif "mấy giờ" in text.lower():
            get_time()
        
        elif "bật" in text.lower():
            device_name = text.lower().split("bật")[1].strip()
            speak(f"{device_name} đã được bật")

        elif "tắt" in text.lower():
            device_name = text.lower().split("tắt")[1].strip()
            speak(f"{device_name} đã được tắt")

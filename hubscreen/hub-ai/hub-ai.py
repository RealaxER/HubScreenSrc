
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

language = "en"

def speak(text):
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
            print(said)
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
    buff = typedef_pb2.Buffer()
    buff.ParseFromString(message.payload)
    if buff.receiver == typedef_pb2.User_t.Value("Ai"):
        print("<-- ", message.topic," : ",buff)
        data_queue.put(buff)

def mqtt_publish(topic, message):
    data = message.SerializeToString()
    client.publish(topic, data)
    print("--> ", topic," : ",message)

client = mqtt.Client(client_id="hub-ai") 
client.on_connect = on_connect
client.on_message = on_message

client.connect("127.0.0.1", 1883, 60)


# Handle name sw and led 
sw_names = []
led_names = []
def mqtt_thread():
    while True:
        client.loop()
        try:
            buff = data_queue.get(block=False)
            for led in buff.led:
                if led.name not in led_names:
                    led_names.append(led.name)
            print("Received LED info:", led_names)

            for sw in buff.sw:
                if sw.name not in sw_names:
                    sw_names.append(sw.name)
            print("Received Sw info:", sw_names)
        except queue.Empty:
            pass
        time.sleep(0.1) 

mqtt_thread = threading.Thread(target=mqtt_thread)
mqtt_thread.daemon = True 
mqtt_thread.start()


buffer = typedef_pb2.Buffer()
buffer.sender = typedef_pb2.User_t.Value("Ai")
buffer.receiver = typedef_pb2.User_t.Value("Hub")
buffer.led.clear()
led = typedef_pb2.Led_t()
led.name = "bedroom"
led.status = True

buffer.led.append(led)
mqtt_publish("hub/ai", buffer)
## handle ai
while True:
    print("Listening")
    text = get_audio()
    if language == "en":

        if "who are" in text.lower():
            speak("I'm hub screen created by Living Lab")

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
            device_name = text.lower().split("turn on")[1].strip()
            buffer.led.clear()
            buffer.sw.clear()
            led = typedef_pb2.Led_t()
            led.name = device_name
            led.status = True

            buffer.led.append(led)
            mqtt_publish("hub/ai", buffer)
            speak(f"{device_name} is turned on")

        elif "turn off" in text.lower():
            device_name = text.lower().split("turn off")[1].strip()
            if device_name in led_names:
                buffer.led.clear()
                led = typedef_pb2.Led_t()
                led.name = device_name

                buffer.led.append(led)
                mqtt_publish("hub/ai", buffer)
                speak(f"{device_name} is turned off")
            elif device_name in sw_names:
                buffer.sw.clear()
                sw = typedef_pb2.Sw_t()
                sw.name = device_name

                buffer.sw.add(led)
                mqtt_publish("hub/ai", buffer)
                speak(f"{device_name} is turned off")
            else :
                speak(f"{device_name} not have")


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
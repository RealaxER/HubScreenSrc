# if you install in rpi you need make python3 in folder toolchain 
sudo apt install python3


# toolchain 
sudo apt-get install python3-pyaudio
sudo apt install -y protobuf-compiler
sudo apt-get install espeak

sudo apt-get install libasound-dev portaudio19-dev libportaudio2 libportaudiocpp0
sudo apt-get install libffi-dev

pip3.8 install pyAudio
pip3.8 install gTTS
pip3.8 install SpeechRecognition
pip3.8 install playsound
pip3.8 install pytz
pip3.8 install datetime
pip3.8 install protobuf




# Run it 
PROTOCOL_BUFFERS_PYTHON_IMPLEMENTATION=python python3 hub-ai.py 

#!/bin/bash

current=$(pwd)
home="$HOME"

# set env 
service_master="/etc/systemd/system/master.service"
cmd_service_master="RUST_LOG=info $home/service/hub-master --mac 8xff >> $home/log/hub-master.log 2>&1"

service_wifi="/etc/systemd/system/wifi.service"
cmd_service_wifi="RUST_LOG=info $home/service/hub-wifi --mac 8xff >> $home/log/hub-wifi.log 2>&1"

service_zigbee="/etc/systemd/system/zigbee.service"
cmd_service_zigbee="$home/service/hub-zigbee >> $home/log/hub-zigbee.log 2>&1"

service_ota="/etc/systemd/system/ota.service"
cmd_service_ota="RUST_LOG=info $home/service/hub-ota --mac 8xff --dir-ota $home/update.zip >> $home/log/hub-ota.log 2>&1"

service_vpn="/etc/systemd/system/vpn.service"
cmd_service_vpn="sudo openvpn $home/service/client1.ovpn"

service_ai="/etc/systemd/system/ai.service"
cmd_service_ai="$home/service/hub-ai >> $home/log/hub-ai.log 2>&1"

service_screen="/etc/systemd/system/screen.service"
cmd_service_screen="$home/service/hub-screen >> $home/log/hub-screen.log 2>&1"

# Check if the "clean" flag is provided
if [[ $1 == "clean" ]]; then
    echo "Cleaning up..."
    cd ${current}/hubscreen/hub-master
    cargo clean

    cd ${current}/hubscreen/hub-ota
    cargo clean

    cd ${current}/hubscreen/hub-wifi
    cargo clean

    cd ${current}/hubscreen/hub-zigbee
    rm -r build

    cd ${current}/hubscreen/hub-ble
    rm -r build

    cd ${current}/hubscreen/hub-ai
    rm -r dist/
    rm -r build/
    rm -r hub-ai.spec 

    echo "Clean-up completed."

elif [[ $1 == "install" ]]; then
    sudo apt update
    echo "Starting up..."
    # Check OpenSSH
    if [ ! -x "$(command -v ssh)" ]; then
        echo "OpenSSH is not installed. Installing..."
        sudo apt install -y openssh-server
        echo "OpenSSH has been installed."
    else
        echo "OpenSSH is already installed."
    fi

    if [ ! -x "$(command -v cmake)" ]; then
        echo "Cmake is not installed. Installing..."
        sudo apt install cmake
        sudo apt install make
        echo "Cmake has been installed."
    else
        echo "Cmake is already installed."
    fi

    # Check Mosquitto
    if [ ! -x "$(command -v mosquitto)" ]; then
        echo "Mosquitto is not installed. Installing..."
        sudo apt install -y mosquitto
        echo "Mosquitto has been installed."
    else
        echo "Mosquitto is already installed."
    fi


    # Check lib mosquitto
    if ! ldconfig -p | grep -q "libmosquitto-dev"; then
        echo "Mosquitto lib is not installed. Installing..."
        sudo apt-get install libmosquitto-dev
    else
        echo "Mosquitto lib is already installed."
    fi

    # # Check rust install 
    if ! command -v rustc &> /dev/null; then
        echo "Rust lib is not installed. Installing..."
        
        echo 1 | curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh -s -- -y
        
        # Thêm Rust vào PATH
        source $HOME/.cargo/env

        echo "Rust installed successfully"
    else
        echo "Rust installed"
    fi

    # Check if build-essential is installed
    if ! dpkg -s build-essential &> /dev/null; then
        echo "build-essential is not installed. Initiating the installation process..."

        # Install build-essential
        sudo apt install -y build-essential

        echo "build-essential has been successfully installed."
    else
        echo "build-essential is already installed."
    fi

    # Check if OpenVPN is installed
    if ! command -v openvpn &> /dev/null; then
        echo "OpenVPN is not installed. Initiating the installation process..."

        # Install OpenVPN
        sudo apt update
        sudo apt install -y openvpn

        echo "OpenVPN has been successfully installed."
    else
        echo "OpenVPN is already installed."
    fi

    # Check if protobuf is installed
    if ! command -v protoc &> /dev/null; then
        echo "Protobuf is not installed. Initiating the download and installation process..."

        # Download protobuf
        sudo apt install -y protobuf-compiler
        sudo apt install libprotobuf-dev

        echo "Protobuf has been successfully installed."
    else
        echo "Protobuf is already installed."
    fi

    # Check and install Python 3 if not installed
    if ! command -v python3 &> /dev/null; then
        echo "Python 3 is not installed, initiating installation..."
        sudo apt update
        sudo apt install -y python3
    fi

    # Check and install python3-pyaudio if not installed
    if ! dpkg -s python3-pyaudio &> /dev/null; then
        echo "python3-pyaudio is not installed, initiating installation..."
        sudo apt-get install -y python3-pyaudio
    fi

    # Check and install espeak if not installed
    if ! command -v espeak &> /dev/null; then
        echo "espeak is not installed, initiating installation..."
        sudo apt-get install -y espeak
    fi
    # Install Python libraries using pip
    echo "Installing Python libraries using pip..."

    pip install pyAudio gTTS SpeechRecognition playsound pytz datetime
    pip install pyinstaller


    echo "Installation complete."

elif [[ $1 == "protoc" ]]; then
    cd ${current}/hubscreen/hub-master/src/proto/
    protoc --rust_out=./ typedef.proto

    cd ${current}/hubscreen/hub-ota/src/proto/
    protoc --rust_out=./ typedef.proto

    cd ${current}/hubscreen/hub-wifi/src/proto/buffer
    protoc --rust_out=./ typedef.proto
    cd ${current}/hubscreen/hub-wifi/src/proto/wifi
    protoc --rust_out=./ wifi.proto

    cd ${current}/hubscreen/hub-ble/proto/ble
    protoc --cpp_out=./ ble.proto
    cd ${current}/hubscreen/hub-ble/proto/hub
    protoc --cpp_out=./ typedef.proto

    cd ${current}/hubscreen/hub-zigbee/proto/zigbee
    protoc --cpp_out=./ zigbee.proto
    cd ${current}/hubscreen/hub-zigbee/proto/hub
    protoc --cpp_out=./ typedef.proto

    cd ${current}/hubscreen/hub-ai
    protoc --python_out=./ typedef.proto


    cd ${current}

    echo "Protoc gen complete."

elif [[ $1 == "build" ]]; then
    # Build program
    cd ${current}/hubscreen/hub-master/
    cargo build --release

    cd ${current}/hubscreen/hub-ota
    cargo build --release

    cd ${current}/hubscreen/hub-wifi
    cargo build --release

    cd ${current}/hubscreen/hub-zigbee
    mkdir -p build 
    cd build
    cmake ..
    make

    cd ${current}/hubscreen/hub-ble
    mkdir -p build 
    cd build
    cmake ..
    make

    cd ${current}
    echo "Build succesfully."

    cd ${current}/hubscreen/hub-screen/generated
    mkdir build 
    cd build
    cmake ..
    make

    cd ${current}/hubscreen/hub-ai
    pyinstaller --onefile hub-ai.py



elif [[ $1 == "upgrade" ]]; then
    mkdir -p ${home}/log/
    mkdir -p ${home}/service/

    sudo systemctl stop ota 
    sudo systemctl stop zigbee 
    sudo systemctl stop master
    sudo systemctl stop screen
    sudo systemctl stop wifi
    sudo cp ${current}/hubscreen/hub-screen/generated/build/hub-screen ${home}/service/
    sudo cp ${current}/hubscreen/hub-ota/target/release/hub-ota ${home}/service/
    sudo cp ${current}/hubscreen/hub-zigbee/build/hub-zigbee ${home}/service/
    sudo cp ${current}/hubscreen/hub-master/target/release/hub-master ${home}/service/
    sudo cp ${current}/hubscreen/hub-wifi/target/release/hub-wifi ${home}/service/
    sudo cp ${current}/client1.ovpn ${home}/service/
    sudo systemctl start ota 
    sudo systemctl start zigbee 
    sudo systemctl start master
    sudo systemctl start screen
    sudo systemctl start wifi
    sudo systemctl enable ota
    sudo systemctl enable wifi 
    sudo systemctl enable zigbee 
    sudo systemctl enable master
    sudo systemctl enable screen

elif [[ $1 == "service" ]]; then
    # Check master.service already
    if [ ! -f "$service_master" ]; then
        sudo echo "File master.service not have already. Initiating the download and installation process..."
        # Info master.service
        sudo echo "[Unit]" > "$service_master"
        sudo echo "Description=Hubscreen Master Service" >> "$service_master"
        sudo echo "After=systend-user-sessions.service" >> "$service_master"
        sudo echo "" >> "$service_master"
        sudo echo "[Service]" >> "$service_master"
        sudo echo "Type=simple" >> "$service_master"
        sudo echo "ExecStart=/bin/bash -c \"$cmd_service_master\"" >> "$service_master"
        sudo chmod 600 $service_master
        sudo echo "Writed master.service to systemd succesfully."
    else
        echo "File master.service already."
    fi

        # Check wifi.service already
    if [ ! -f "$service_wifi" ]; then
        sudo echo "File wifi.service not have already. Initiating the download and installation process..."
        # Info master.service
        sudo echo "[Unit]" > "$service_wifi"
        sudo echo "Description=Hubscreen Wifi Service" >> "$service_wifi"
        sudo echo "After=systend-user-sessions.service" >> "$service_wifi"
        sudo echo "" >> "$service_wifi"
        sudo echo "[Service]" >> "$service_wifi"
        sudo echo "Type=simple" >> "$service_wifi"
        sudo echo "ExecStart=/bin/bash -c \"$cmd_service_wifi\"" >> "$service_wifi"
        sudo chmod 600 $service_wifi
        sudo echo "Writed wifi.service to systemd succesfully."
    else
        echo "File wifi.service already."
    fi

    # Check zigbee.service already
    if [ ! -f "$service_zigbee" ]; then
        sudo echo "File zigbee.service not have already. Initiating the download and installation process..."
        # Info zigbee.service
        sudo echo "[Unit]" > "$service_zigbee"
        sudo echo "Description=Hubscreen Zigbee Service" >> "$service_zigbee"
        sudo echo "After=systend-user-sessions.service" >> "$service_zigbee"
        sudo echo "" >> "$service_zigbee"
        sudo echo "[Service]" >> "$service_zigbee"
        sudo echo "Type=simple" >> "$service_zigbee"
        sudo echo "ExecStart=/bin/bash -c \"$cmd_service_zigbee\"" >> "$service_zigbee"
        sudo chmod 600 $service_zigbee
        sudo echo "Writed zigbee.service to systemd succesfully."
    else
        echo "File zigbee.service already."
    fi


    # Check ota.service already
    if [ ! -f "$service_ota" ]; then
        sudo echo "File ota.service not have already. Initiating the download and installation process..."
        # Info ota.service
        sudo echo "[Unit]" > "$service_ota"
        sudo echo "Description=Hubscreen Ota Service" >> "$service_ota"
        sudo echo "After=systend-user-sessions.service" >> "$service_ota"
        sudo echo "" >> "$service_ota"
        sudo echo "[Service]" >> "$service_ota"
        sudo echo "Type=simple" >> "$service_ota"
        sudo echo "ExecStart=/bin/bash -c \"$cmd_service_ota\"" >> "$service_ota"
        sudo chmod 600 $service_ota
        sudo echo "Writed ota.service to systemd succesfully."
    else
        echo "File ota.service already."
    fi

     # Check vpn.service already
    if [ ! -f "$service_vpn" ]; then
        sudo echo "File vpn.service not have already. Initiating the download and installation process..."
        # Info vpn.service
        sudo echo "[Unit]" > "$service_vpn"
        sudo echo "Description=Hubscreen Vpn Service" >> "$service_vpn"
        sudo echo "After=systend-user-sessions.service" >> "$service_vpn"
        sudo echo "" >> "$service_vpn"
        sudo echo "[Service]" >> "$service_vpn"
        sudo echo "Type=simple" >> "$service_vpn"
        sudo echo "ExecStart=/bin/bash -c \"$cmd_service_vpn\"" >> "$service_vpn"
        sudo chmod 600 $service_vpn
        sudo echo "Writed vpn.service to systemd succesfully."
    else
        echo "File vpn.service already."
    fi

    # Check ai.service already
    if [ ! -f "$service_ai" ]; then
        sudo echo "File ai.service not have already. Initiating the download and installation process..."
        # Info ai.service
        sudo echo "[Unit]" > "$service_ai"
        sudo echo "Description=Hubscreen ai Service" >> "$service_ai"
        sudo echo "After=systend-user-sessions.service" >> "$service_ai"
        sudo echo "" >> "$service_ai"
        sudo echo "[Service]" >> "$service_ai"
        sudo echo "Type=simple" >> "$service_ai"
        sudo echo "Environment="PROTOCOL_BUFFERS_PYTHON_IMPLEMENTATION=python"" >> "$service_ai"
        sudo echo "ExecStart=/bin/bash -c \"$cmd_service_ai\"" >> "$service_ai"
        sudo chmod 600 $service_ai
        sudo echo "Writed ai.service to systemd succesfully."
    else
        echo "File ai.service already."
    fi

    # Check screen.service already
    if [ ! -f "$service_screen" ]; then
        sudo echo "File screen.service not have already. Initiating the download and installation process..."
        # Info screen.service
        sudo echo "[Unit]" > "$service_screen"
        sudo echo "Description=Hubscreen screen Service" >> "$service_screen"
        sudo echo "After=systend-user-sessions.service" >> "$service_screen"
        sudo echo "" >> "$service_screen"
        sudo echo "[Service]" >> "$service_screen"
        sudo echo "Type=simple" >> "$service_screen"
        sudo echo "ExecStart=/bin/bash -c \"$cmd_service_screen\"" >> "$service_screen"
        sudo chmod 600 $service_screen
        sudo echo "Writed screen.service to systemd succesfully."
    else
        echo "File screen.service already."
    fi

else 
    echo "Usage:./build.sh [install|upgrade|clean|protoc|service]"
fi

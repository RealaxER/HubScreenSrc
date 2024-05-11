#!/bin/bash

current=$(pwd)
home="$HOME"

# Thiết lập các biến dịch vụ và lệnh dịch vụ
service_master="/etc/systemd/system/master.service"
cmd_service_master="RUST_LOG=info $home/service/hub-master --mac 8xff --dir-ota $home/update.zip >> $home/log/hub-master.log 2>&1"

service_zigbee="/etc/systemd/system/zigbee.service"
cmd_service_zigbee="RUST_LOG=info $home/service/hub-zigbee --mac 8xff >> $home/log/hub-zigbee.log 2>&1"

service_ota="/etc/systemd/system/ota.service"
cmd_service_ota="RUST_LOG=info $home/service/hub-ota --mac 8xff >> $home/log/hub-ota.log 2>&1"

service_vpn="/etc/systemd/system/vpn.service"
cmd_service_vpn="sudo openvpn $home/service/client1.ovpn"

# Check if the "clean" flag is provided
if [[ $1 == "clean" ]]; then
    echo "Cleaning up..."
    cd ${current}/hubscreen/hub-master
    cargo clean

    cd ${current}/hubscreen/hub-ota
    cargo clean

    cd ${current}/hubscreen/hub-zigbee
    rm -r build
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

    # Check Mosquitto
    if [ ! -x "$(command -v mosquitto)" ]; then
        echo "Mosquitto is not installed. Installing..."
        sudo apt install -y mosquitto
        echo "Mosquitto has been installed."
    else
        echo "Mosquitto is already installed."
    fi


    # Check lib mosquitto
    if ! ldconfig -p | grep -q "libmosquitto"; then
        echo "Mosquitto lib is not installed. Installing..."
        sudo apt install mosquitto-dev
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

        echo "Protobuf has been successfully installed."
    else
        echo "Protobuf is already installed."
    fi


    # # Build program
    cd ${current}/hubscreen/hub-master
    cargo build --release

    cd ${current}/hubscreen/hub-ota
    cargo build --release

    cd ${current}/hubscreen/hub-zigbee
    mkdir build 
    cd build
    cmake ..
    make

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




elif [[ $1 == "upgrade" ]]; then
    mkdir -p ${home}/log/
    mkdir -p ${home}/service/

    sudo systemctl stop hub-ota 
    sudo systemctl stop hub-zigbee 
    sudo systemctl stop hub-master
    sudo cp ${current}/hubscreen/hub-zigbee/target/release/hub-ota ${home}/service/
    sudo cp ${current}/hubscreen/hub-zigbee/target/release/hub-zigbee ${home}/service/
    sudo cp ${current}/hubscreen/hub-zigbee/target/release/hub-master ${home}/service/
    sudo cp ${current}/client1.ovpn ${home}/service/
    sudo systemctl start hub-ota 
    sudo systemctl start hub-zigbee 
    sudo systemctl start hub-master
    sudo systemctl enable hub-ota 
    sudo systemctl enable hub-zigbee 
    sudo systemctl enable hub-master

else 
    echo "Usage:./build.sh [install|upgrade|clean]"
fi

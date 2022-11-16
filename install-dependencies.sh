#!/bin/bash
# USAGE: ./install-dependencies.sh
# Use once to install all of the packages I (Corbin) use.
# Trying to ignore all GUI apps for terminal-only purposes.
#   general
sudo apt install -y git
#   device configuration
# used for mkpasswd
sudo apt install -y whois
sudo apt install -y screen
sudo apt install -y tar
#   networking
sudo apt install -y net-tools
sudo apt install -y netcat
sudo apt install -y nmap
sudo apt install -y samba
sudo apt install -y sshfs
sudo apt install -y wget
#sudo apt install -y openvpn # Don't have a way to utilize this yet.
#   Python
sudo apt install -y python3
sudo apt install -y python3-pip
#   terminal graphics
sudo apt install -y whiptail
sudo apt install -y x11-apps

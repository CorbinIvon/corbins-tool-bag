#!/bin/bash
# USAGE: ./insert-user.sh [$1 USER NAME] [$2 TARGET ROOT DIR]

# Create passwd
sha_pass=$(mkpasswd -m sha-512)
# etc/passwd
sudo cp $2/etc/passwd .
sudo chmod 666 passwd
cat passwd
read -p "UID: " uid
read -p "GID: " gid
read -p "Comment: " comment
echo "$1:$sha_pass:$uid:$gid:$comment:/home/$1:/bin/bash" >> passwd
sudo chmod 644 passwd
sudo cp passwd $2/etc/passwd
# etc/group
sudo cp $2/etc/group .
sudo chmod 666 group
echo "$1:x:$gid:" >> group
sudo chmod 644 group
sudo cp group $2/etc/group
# /home/user
sudo mkdir $2/home/$1
sudo cp .bashrc $2/home/$1
sudo chown $1:$1 $2/home/$1
sudo chown $1:$1 $2/home/$1/.bashrc
# /etc/skel
sudo cp -r /skel/* $2/home/$1/

# clean up
sudo rm passwd group
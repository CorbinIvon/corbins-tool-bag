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
echo "$1:x:$uid:$gid:$comment:/home/$1:/bin/bash" >> passwd
sudo chmod 644 passwd
sudo cp passwd $2/etc/passwd
# etc/shadow
sudo cp $2/etc/shadow .
sudo chmod 666 shadow
sudo echo "$1:$sha_pass:$(date +%s):0:99999:7:::" >> shadow
sudo chmod 640 shadow
sudo chown root:shadow shadow
sudo cp shadow $2/etc/shadow
# etc/group
sudo cp $2/etc/group .
sudo chmod 666 group
echo "$1:x:$gid:" >> group
sudo chmod 644 group
sudo cp group $2/etc/group
# /etc/sudoers
sudo cp $2/etc/sudoers .
sudo chmod 666 sudoers
sudo echo "$1   ALL=(ALL:ALL) ALL" >> sudoers
sudo chmod 440 sudoers
sudo chown root:root sudoers
sudo cp sudoers $2/etc/sudoers
# /home/user
sudo cp -r skel/ $2/home/
sudo mv $2/home/skel $2/home/$1
sudo chown $1:$1 $2/home/$1
# clean up
sudo rm passwd group shadow sudoers
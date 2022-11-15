#!/bin/bash
# USAGE: ./insert-user.sh [$1 USER NAME] [$2 TARGET ROOT DIR]

# Create passwd

# Copy etc/passwd
sudo cp $2/etc/passwd .
sudo chmod 666 passwd
echo "$1" >> passwd
sudo chmod 644 passwd

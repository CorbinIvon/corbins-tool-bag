#!/bin/bash
# USAGE: ./ping-list.sh [input]
# https://askubuntu.com/questions/413367/ping-multiple-ips-using-bash
date
cat $1 |  while read output
do
    ping -c 1 "$output" > /dev/null
    if [ $? -eq 0 ]; then
    echo "node $output is up"
    else
    echo "node $output is down"
    fi
done

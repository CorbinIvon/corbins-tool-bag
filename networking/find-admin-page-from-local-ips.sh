#!/bin/bash
RES=$(nmap -sn 192.168.1.0/24)
OUTPUT=$(echo "$RES" | grep -E '[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}' | sed 's/Nmap scan report for //g')
OUTPUT_RAW=$(echo $OUTPUT | grep -o '[0-9]\{1,3\}\.[0-9]\{1,3\}\.[0-9]\{1,3\}\.[0-9]\{1,3\}')
echo "$OUTPUT_RAW" > ips-out.raw
ips=$(echo "$OUTPUT_RAW")
for ip in $ips
do
        chromium "$ip/admin"
done

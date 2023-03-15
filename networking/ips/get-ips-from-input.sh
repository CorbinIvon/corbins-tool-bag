#!/bin/bash
# USAGE: ./get-ips-from-input.sh [FILE WITH IPs]
OUTPUT=$(grep -E '[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}' $1 | sed 's/Nmap scan report for //g')
echo "$OUTPUT" > ips-out.txt
OUTPUT_RAW=$(echo $OUTPUT | grep -o '[0-9]\{1,3\}\.[0-9]\{1,3\}\.[0-9]\{1,3\}\.[0-9]\{1,3\}')
echo "$OUTPUT_RAW" > ips-out.raw
echo ips-out.txt and ips-out.raw created.

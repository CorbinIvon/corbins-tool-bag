#!/bin/bash
# USAGE: ./nmap-bulk.sh [FILE WITH IPS]
ips=$(cat $1)
for ip in $ips
do
	nmap "$ip"
done

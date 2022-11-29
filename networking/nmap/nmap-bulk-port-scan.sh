#!/bin/bash
# USAGE: ./nmap-bulk-port-scan.sh [FILE WITH IPs]
ips=$(cat $1)
for ip in $ips
do
	nmap "$ip"
done

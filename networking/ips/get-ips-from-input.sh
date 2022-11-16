#!/bin/bash
# USAGE: ./get-ips-from-input.sh [FILE WITH IPs]
grep -E '[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}' $1 | sed 's/Nmap scan report for //g' >> ips.txt

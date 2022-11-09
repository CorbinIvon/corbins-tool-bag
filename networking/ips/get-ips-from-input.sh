#!/bin/bash
# USAGE: ./get-ips-from-input.sh [input]
grep -E '[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}' $1

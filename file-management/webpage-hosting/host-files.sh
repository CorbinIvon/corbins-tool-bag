#!/bin/bash
# This script starts a php server under the
# vpn / local host for running the index.php
# file. Refer to the:
# create-downloadable-vpn-links.php

echo "[1] vpn"
echo "[2] local"
read -p "Host method [1]: " host_option
case "$host_option" in
  1|"")
    host_option="10.3.0.1:1234"
  ;;
  2)
    host_option="192.168.1.9:1234"
  ;;
esac
echo "Hosting @ http://$host_option"
php -S $(echo "$host_option")

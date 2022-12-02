result=$(ping -c 1 -w 1 192.168.1.204 | grep "1 received")
if [ -z "$result"  ]
then
	echo "device is offline"
else
	echo "device is online"
fi

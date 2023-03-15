# Can also ping by dns. Corbin-Phone would work.
# use nslookup to make sure you have the correct name
#result=$(ping -c 1 -w 1 192.168.1.204 | grep "1 received")
result=$(ping -c 1 -w 1 Phone-Corbin | grep "1 received")
if [ -z "$result"  ]
then
	#echo "device is offline"
	echo "false"
else
	#echo "device is online"
	echo "true"
fi

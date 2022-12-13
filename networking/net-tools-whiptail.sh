#! /bin/bash

# This program is just an example of how to make a whiptail menu and some basic commands.
# Copyright (C) 2016  Baljit Singh Sarai

# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

clear


function contextSwitch {
	{
	ctxt1=$(grep ctxt /proc/stat | awk '{print $2}')
        echo 50
	sleep 1
        ctxt2=$(grep ctxt /proc/stat | awk '{print $2}')
        ctxt=$(($ctxt2 - $ctxt1))
        result="Number os context switches in the last secound: $ctxt"
	echo $result > result
	} | whiptail --gauge "Getting data ..." 6 60 0
}



function userKernelMode {
	{
	raw=( $(grep "cpu " /proc/stat) )
        userfirst=$((${raw[1]} + ${raw[2]}))
        kernelfirst=${raw[3]}
	echo 50
        sleep 1
	raw=( $(grep "cpu " /proc/stat) )
        user=$(( $((${raw[1]} + ${raw[2]})) - $userfirst ))
	echo 90
        kernel=$(( ${raw[3]} - $kernelfirst ))
        sum=$(($kernel + $user))
        result="Percentage of last sekund in usermode: \
        $((( $user*100)/$sum ))% \
        \nand in kernelmode: $((($kernel*100)/$sum ))%"
	echo $result > result
	echo 100
	} | whiptail --gauge "Getting data ..." 6 60 0
}

function interupts {
	{
	ints=$(vmstat 1 2 | tail -1 | awk '{print $11}')
        result="Number of interupts in the last secound:  $ints"
	echo 100
	echo $result > result
	} | whiptail --gauge "Getting data ..." 6 60 50
}

while [ 1 ]
do
CHOICE=$(
whiptail --title "Network Tools" --menu "Make your choice" 16 100 9 \
	"Show Global IPv4" "" \
	"Show Global Network Open Ports" "" \
	"Show Local IPv4" "" \
	"Show Local Open Ports" "" \
	"Show Devices On Same Network" "" \
	"exit" ""  3>&2 2>&1 1>&3
)


result="result placeholder"
case $CHOICE in
	"Show Global IPv4")
		result="My global IP is:\n"$(dig +short myip.opendns.com @resolver1.opendns.com)
	;;

	"Show Global Network Open Ports")
       		global_ip=$(dig +short myip.opendns.com @resolver1.opendns.com)
		result=$(nmap $global_ip)
		echo "$result" | less
	;;

	"Show Local IPv4")
		result=$(ip -4 addr show eth0 | grep -oP '(?<=inet\s)\d+(\.\d+){3}')
        ;;

	"Show Local Open Ports")
		local_ip=$(ip -4 addr show eth0 | grep -oP '(?<=inet\s)\d+(\.\d+){3}')
		result=$(nmap $local_ip)
		echo "$result" | less
	;;

	"Show Devices On Same Network")
		result=$(\
			ip -o addr show dev "eth0" | \
			awk '$3 == "inet" {print $4}' | \
			nmap -sn `xargs` | \
			grep -E '[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}' | \
			sed 's/Nmap scan report for //g' \
		)
		#echo "$result" > local-network-devices.txt
		echo "$result" | less
        ;;

	"exit") exit
        ;;
esac
#whiptail --msgbox "$result" 20 78
whiptail --msgbox "$result" $(tput lines) $(tput cols)
done
exit
#			sed 's/\.hsd1\.ca\.comcast\.net//g' \


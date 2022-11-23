#!/bin/bash
# USAGE: ./msg-me.sh [LINUX COMMAND]
echo You will be notified upon task completion.
timestamp=$(date +%s)
$($1)
endtime=$(($(date +%s)-$timestamp))
$(notify-send "Finished Running" "Time Elapsed: $endtime\nApplication: $1")

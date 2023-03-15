#!/bin/bash
# Reads from check-servers-list.txt to get status. Compares it with other servers.
# Will display a detailed notification when the status is down from a server.
# This script is ChatGPT assisted.

# Set the filename to be passed as an argument
#filename=$1
filename="links.txt"

# Check if a file was passed as an argument
#if [[ -z "$filename" ]]; then
#  echo "No file was provided. Please provide a filename as an argument."
#  exit 1
#fi

# Check if the file exists
if [[ ! -f "$filename" ]]; then
  echo "The file $filename does not exist."
  exit 1
fi

# Loop through each line in the file
while read -r line; do
  # Process the line here
  #echo "Processing line: $line"
  # Do something with each line
  url="$line"

  if [[ "$line" != \#* ]]; then
    # Use curl to check the HTTP status code of the URL
    status_code=$(curl -s -o /dev/null -w "%{http_code}" "$url")

    # Status codes: https://developer.mozilla.org/en-US/docs/Web/HTTP/Status
    # If the status code is not 200, send a notification
    if [ "$status_code" != "200" ] && [ "$status_code" != "301" ]; then
      notify-send "$url is down: $status_code" "The web site $url is down. HTTP status code: $status_code"
    fi
  fi
done < "$filename"

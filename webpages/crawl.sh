#!/bin/bash
# Usage: ./crawl https://URL.url
# This script will get every external link on a domain. This is to check to see if a link on a site is broken for some reason.
# Function to get all links on a webpage
get_links() {
  curl -s $1 | grep -o 'href="[^"]*"' | cut -d'"' -f2
}
# Recursive function to go through every link on a page.
crawl() {
  url="$1"
  # Check if the page has already been crawled. If it has, return.
  if grep -Fxq "$url" "$crawled_file"; then
    # echo "$url already crawled"
    return
  fi
  # Add this url to the pages crawled file.
  echo "$url" >> "$crawled_file"
  # get the links from this url.
  links="$(get_links "$url")"
  # echo "$links"
  # exit 1
  # add every link to the links.crawl file as "url" > "link"
  echo "Crawling: $url"
  echo >> "$links_file"
  echo "Source: $url" >> "$links_file"
  for link in $links; do
    if [[ "${link:0:1}" == "/" ]]; then
      link=$PAGE_HOME$link
    fi

    echo "-- $link" >> "$links_file"
  done
  # check if the link is still part of the domain. If not, do nothing.
  for link in $links; do
    if [[ "${link:0:1}" == "/" ]]; then
      link=$PAGE_HOME$link
    fi

    if echo "$link" | grep -q "$DOMAIN"; then
      # if the link is part of the same domain, recursively go into these links and call this function again.
      # echo "$link"
      crawl "$link"
    else
      : # echo "$link != $DOMAIN"
    fi
  done
}
# if the link is part of the same domain, recursively go into these links and call this function again.
PAGE_HOME=$1
DOMAIN=$(echo $PAGE_HOME | sed 's#^\(https\?://\)##')
crawled_file="internal.$DOMAIN.txt"
links_file="links.$DOMAIN.txt"
external_file="external.$DOMAIN.txt"
rm -f $crawled_file $links_file
touch $crawled_file
crawl "$PAGE_HOME"
cat $links_file | sort | uniq | grep "\-\-" | sed "s/\-\- //g" | grep http | grep -v $DOMAIN > $external_file
echo "Please run the following command to check external links:"
echo "cat $external_file | xargs -I {} chromium {}"

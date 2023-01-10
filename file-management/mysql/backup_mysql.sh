#!/bin/bash
TIMESTAMP=$(date +%s)
#echo $TIMESTAMP

# Show all databases. Store them in a list.
mysql_lists=$(mysql --execute="SHOW DATABASES" | grep -v "| " | sed '1d')

### Backup function here. ###
# Create a directory based on the database name to store the backups.
function create_backup {
  mysqldump $1 > $1-$TIMESTAMP.sql
}

function restore_backup {
  return
}


if [[ $# -eq 0 ]]; then
  echo "No arguments passed"
  # return
else
  echo "Argument passed: $1"
  # while read line; do
  #   create_backup ($line)
  # done < "$mysql_lists"
  # exit 0
fi



echo "What would you like to do?"
echo "   1) Back up all mysql databases"
echo "   2) Back up a single mysql database"
echo "   3) Restore a single mysql database"
read -p "Action [1]: " action
until [[ -z "$action" || "$action" =~ ^[123]$ ]]; do
  echo "$action: invalid selection."
  read -p "Action [1]: " action
done
case "$action" in
  1|"")
    echo "Please select a database:"
    for line in $(echo "$mysql_lists"); do
      create_backup $line
      echo "Backed up: $line"
    done
    echo
    echo "[ BACKUP COMPLETE ]"
    echo
    exit 0
  ;;
  2)
    index=0
    echo "Please select a database:"
    for line in $(echo "$mysql_lists"); do
      index=$(expr $index + 1)
      echo "$index) $line"
    done

  ;;
  3) 


  ;;
esac

exit 0
# Read the parameters passed in. If there are no parameters, prompt for parameters.
#   [1] - back up all data (default)
#   [2] - back up single database
#   [3] - restore from backup (lists out all backups)


### BACK UP ALL DATABASES ###
# call backup function for every database.

### BACK UP SPECIFIED DATABASE ###
# Prompt the user which database to back up.
# call backup function for that database.

### RESTORE DATABASE ###
# List out all databases.
# Select a database.
# Confirm it's correct.
# Start restore.

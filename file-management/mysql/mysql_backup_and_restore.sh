#!/bin/bash
## Version : 1.0.0
## Date    : 2023-01-10
## Created by Corbin Meier.
##  ChatGPT Assisted.
##
## DESCRIPTION: A script that manages mysql backups and restores. Should be very user
##              friendly for anyone to use (even if they're just getting started).
##              Can also be used in a crontable for frequent autonomous backups. Make
##              sure to include the " all" argument.
##
## NOTE:        This script will not restore a database that does not have backups.
##              If you want to restore / copy a file to a new databse, you will need
##              to create the new database in mysql, create a backup, move the
##              targeted restore file into the new directory, and then run the
##              restore. I will probably create this feature in the future, but do
##              not have a need to do so right now.
##
TIMESTAMP=$(date +%s)
mysql_lists=$(mysql --execute="SHOW DATABASES" | grep -v "| " | sed '1d')
backup_dir=$(pwd)/backups

# Create a directory based on the database name to store the backups.
function create_backup {
  mkdir -p $backup_dir/$1
  mysqldump $1 > $backup_dir/$1/$1-$TIMESTAMP.sql
  echo "Backup Created: $backup_dir/$1/$1-$TIMESTAMP.sql"
}


# [ Arg ] in ALL to backup all databases.
# [ Arg ] in database to backup specified database.
if [[ $# -gt 0 ]]; then
  if [[ $1 == "all" || $1 == "All" || $1 == "ALL" ]]; then
    # Backup all.
    for line in $(echo "$mysql_lists"); do
      create_backup $line
    done
    exit 0
  elif echo "$mysql_lists" | grep -q -x "$1"; then
    # Backup selected.
    create_backup $1
    exit 0
  else
    # Invalid database.
    echo "Invalid database: $1"
    exit 1
  fi
fi

echo "What would you like to do?"
echo "   1) Backup all databases"
echo "   2) Backup select database"
echo "   3) Restore database"

read -p "Action [1]: " action
until [[ -z "$action" || "$action" =~ ^[123]$ ]]; do
  echo "$action: invalid selection."
  read -p "Action [1]: " action
done
case "$action" in
  1|"")
    # Backup all databases.
    echo "Please select a database:"
    for line in $(echo "$mysql_lists"); do
      create_backup $line
    done
    exit 0
  ;;
  2)
    # Backup chosen database.
    index=0
    echo "Please select a database:"
    for line in $(echo "$mysql_lists"); do
      index=$(expr $index + 1)
      echo "$index) $line"
    done
    read -p "Database number: " database_number
    until [[ "$database_number" -ne 0 && "$database_number" =~ ^[0-9]+$ && "$database_number" -le $(echo "$mysql_lists" | wc -l) ]]; do
      echo "$database_number: Invalid selection."
      read -p "Database number: " database_number
    done
    create_backup $(echo "$mysql_lists" | sed -n "$database_number"p)
    exit 0
  ;;
  3)
    ### RESTORE DATABASE OPTION ###
    # List databases from backups dir, choose 1
    databases_in_backups_directory=$(ls -1 $backup_dir)
    echo
    echo "Please select a database:"
    index=0
    for line in $(echo "$databases_in_backups_directory"); do
      index=$(expr $index + 1)
      echo "$index) $line"
    done
    read -p "Database number: " database_backup_selection
    until [[ "$database_backup_selection" -ne 0 && "$database_backup_selection" =~ ^[0-9]+$ && "$database_backup_selection" -le $(echo "$databases_in_backups_directory" | wc -l) ]]; do
      echo "$database_backup_selection: Invalid selection."
      read -p "Database number: " database_backup_selection
    done
    target_database=$(echo "$databases_in_backups_directory" | sed -n "$database_backup_selection"p)
    backup_database_dir=$backup_dir/$target_database
    # List all backups, convert timestamp to readable date.
    backups=$(ls -1 $backup_database_dir)
    echo
    echo "Please select a backup:"
    index=0
    for line in $(echo "$backups"); do
      index=$(expr $index + 1)
      this_timestamp=$(echo "$line" | cut -d '-' -f 2)
      this_file=$line
      line=$(basename "${line%%-*}")
      echo "$index) $(date -d @"${this_timestamp%.*}" +"%Y-%m-%d %H:%M:%S") ($this_file)"
    done
    read -p "Backup number: " backup_selection
    until [[ "$backup_selection" -ne 0 && "$backup_selection" =~ ^[0-9]+$ && "$backup_selection" -le $(echo "$backups" | wc -l) ]]; do
      echo "$backup_selection: Invalid selection."
      read -p "Backup number: " backup_selection
    done
    backup_file_name=$(echo "$backups" | sed -n "$backup_selection"p)
    backup_file=$backup_database_dir/$backup_file_name
    echo
    echo "You may want to backup $target_database as a safety precaution."
    read -p "Backup $target_database? [y/N]: " safety_backup
    until [[ "$safety_backup" =~ ^[yYnN]*$ ]]; do
      echo "$safety_backup: invalid selection."
      read -p "Backup $target_database? [y/N]: " safety_backup
    done
    if [[ "$safety_backup" =~ ^[yY]$ ]]; then
      create_backup $target_database
    else
      echo
      echo "You chose not to backup $target_database"
    fi
    echo
    echo "WARNING: This will DELETE THE DATA from DATABASE:    $target_database"
    echo "It will be REPLACED WITH the data from RESTORE FILE: $backup_file_name"
    read -p "Begin restore? [y/N]: " restore
    until [[ "$restore" =~ ^[yYnN]*$ ]]; do
      echo "$restore: invalid selection."
      read -p "Begin restore? [y/N]: " restore
    done
    if [[ "$restore" =~ ^[nN]$ ]]; then
      echo "Restore aborted."
      exit 0
    fi
    echo
    echo "DATABASE:     $target_database"
    echo "RESTORE FILE: $backup_file_name"
    read -p "Are you sure? [y/N]: " restore
    until [[ "$restore" =~ ^[yYnN]*$ ]]; do
      echo "$restore: invalid selection."
      read -p "Are you sure? [y/N]: " restore
    done
    if [[ "$restore" =~ ^[yY]$ ]]; then
      echo
      echo "[ RUNNING COMMAND ]"
      echo "mysql $target_database < $backup_file"
      echo
      mysql $target_database < $backup_file
      echo "[ RESTORE COMPLETE ]"
      exit 0
    else
      echo "Restore aborted."
      exit 0
    fi
  ;;
esac
exit 1
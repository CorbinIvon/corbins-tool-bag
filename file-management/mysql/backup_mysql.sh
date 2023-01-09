#!/bin/bash
TIMESTAMP=$(date +%s)
#echo $TIMESTAMP

# Show all databases. Store them in a list.
mysql --execute="SHOW DATABASES"

# Read the parameters passed in. If there are no parameters, prompt for parameters.
#   [1] - back up all data (default)
#   [2] - back up single database
#   [3] - restore from backup (lists out all backups)


### Backup function here. ###
# Create a directory based on the database name to store the backups.


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

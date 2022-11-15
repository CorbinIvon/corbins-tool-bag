#!/bin/bash
# USAGE: ./view-users.sh [ROOT DIR]
cut -d: -f1 $1/etc/passwd

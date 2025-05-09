#!/bin/bash
#getsize.sh

# Check if file or directory
if [ -d $1 ] 
	then 
		ls -l -d $1 | tr -s ' ' | cut -d " " -f "5"
elif [ -f $1 ] 
	then
		ls -l $1 | tr -s ' ' | grep "$1" | cut -d ' ' -f "5"
else
	echo "ERROR: File $1 does not exist" 1>&2
fi

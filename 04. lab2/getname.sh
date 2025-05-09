#!/bin/bash
#getname.sh

if [ -z $1 ]
then 
	echo "You must give an argument!"
else
	grep "^$1" /etc/passwd | cut -d ":" -f "5"
fi	

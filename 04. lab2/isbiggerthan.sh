#!/bin/bash
#isbiggerthan.sh
#umbertofontana.it

#Write a script which takes as argument a path and a size and determines if the file or directory is bigger (or equal to) the given size. Usage: ./isbiggerthan.sh size path
#You must implement error checking. All error output should be printed to stderr.
#See IC221 Lab 2 for more info.

if [ $# -eq 2 ] #Check if either arguments are empty
then
	if [ "$1" -eq "$1" ] #Check if argument $1 is a number
	then
		if [ $1 -gt 0 ] || [ $1 -eq 0 ] #Check that the size is a positive number
		then
			if [ -d $2 ] 
			then #Argument 2 is a directory
				sz="$(ls -l -d $2 | tr -s ' ' | cut -d " " -f "5")" #Get directory size and store it as a variable with command substitution/subshells
				if [ $sz -gt $1 ] || [ $sz -eq $1 ] #Compare sizes
				then
					echo "yes"
				else
					echo "no"
				fi
			elif [ -f $2 ] 
			then #Argument 2 is a file
				sz="$(ls -l $2 | tr -s ' ' | grep "$2" | cut -d ' ' -f "5")" #Get file size and store it as a variable with command substitution/subshells
				if [ $sz -gt $1 ] || [ $sz -eq $1 ] #Compare sizes
				then
					echo "yes"
				else
		       			echo "no"
				fi

			else #Catch error for non-existent files
				echo "ERROR: File $2 does not exist" 1>&2
			fi

		else #Catch error for negative size numbers 
			echo "ERROR: Require a positive number for size" 1>&2
		fi	
	else #Catch error for invalid size values
		echo "ERROR: Require a number for size" 1>&2
	fi
else #Catch error for unprovided arguments
	echo "ERROR: Require path and size" 1>&2
fi

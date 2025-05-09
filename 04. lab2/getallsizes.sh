#!/bin/bash
#getallsizes.sh

for arg in $*
do
	if [ -e $arg ] && [ -f $arg ] ; then echo -n "$arg " && ls -l $arg | grep $arg | tr -s ' ' | cut -d ' ' -f 5; else echo -n "ERROR: File $arg does not exist" 1>&2 ; fi
done

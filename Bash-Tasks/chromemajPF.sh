#!/bin/bash


pagefaultprint(){
var=$(ps --no-headers -o maj_flt "$1")

printf "Chrome %d har foraasaket %d major page faults " "$1" "$var"
	if [ "$var" -gt 1000 ] 
		then
			printf " (Mer enn 1000!)\n"
		else
			printf "\n"
	fi
}


pgrep chrome | while read -r line ; do 
	pagefaultprint "$line"
done


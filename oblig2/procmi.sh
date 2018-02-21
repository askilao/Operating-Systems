#!/bin/bash

memgrep(){
	printf "%d" "$(grep -e "$1" /proc/"$2"/status | awk '{print $2}')"
}

memstat(){

	echo "********* Minne info om prosess med PID $1 *********"
	echo "Total bruk av virtualt minne (VmSize): $(memgrep VmSize "$1")kb"
	echo "Mengde privat virtuelt minne (VmData + VmStk + VmExe): $(($(memgrep VmData "$1")+$(memgrep VmStk "$1")+$(memgrep VmExe "$1")))kb"
	echo "Menge shared virtuelt minne (VmLib): $(memgrep VmLib "$1")kb"
	echo "Total bruk av fysisk minne (VmRss): $(memgrep VmRSS "$1")kb"
	echo "Mengde fysisk minne som benyttes til page table (VmPTE): $(memgrep VmPTE "$1")kb"	

}


for i in "$@"
do
	memstat "$i" > "$i"-"$(date +"%d_%m_%y_%R")".meminfo
done



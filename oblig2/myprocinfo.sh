#!/bin/bash

while true
do	#menyen ligger i fil
	cat menu.txt
	printf "\n"
	read -p "Valg:" input
        printf "\n"	
	case $input in
		1) echo "Jeg er $(whoami) og scriptet heter $0"
			;;
		#uptime gir antall minutt og timer siden boot
		2)echo "$(uptime | awk '{print $3}') time(r) siden boot"
			;;
		#ps aux lister prosesser linje for linje, saa telles de
		3)echo "Det er $(ps aux | wc -l) prosesser og traader som kjorer"
			;;
		#Henter ut context switches venter et sekund og henter paa nytt sa substraherers de to
		4)	first=$(grep ctxt /proc/stat | awk '{print $2}')
			sleep 1
			second=$(grep ctxt /proc/stat | awk '{print $2}')
			echo "Det skjedde $((second-first)) context switches det siste sekundet"
			;;

		#cpu viser totalt for alle cpu kjerner, kolonne 2 er usermode og 4 er system(kernel) mode
		5) 	userfirst=$(grep cpu /proc/stat | awk 'NR==1{print $2}')
			kernelfirst=$(grep cpu /proc/stat | awk 'NR==1{print $4}')
			sleep 1
			usersecond=$(grep cpu /proc/stat | awk 'NR==1{print $2}')
			kernelsecond=$(grep cpu /proc/stat | awk 'NR==1{print $4}')
			
			echo "Det siste sekunded var CPU'en $((usersecond-userfirst)) jiffies i usermode og $((kernelsecond-kernelfirst)) jiffies i kernelmode"				
			;;
		#samme som i 4 bare med intr i grep
		6)	first=$(grep intr /proc/stat | awk 'NR==1{print$2}')
			sleep 1
			second=$(grep intr /proc/stat | awk 'NR==1{print$2}')
			echo "Det var $((second-first)) interupts det siste sekundet"
			;;
		9) exit 0 
	esac	
done





# Oblig 1 IMT2282 Operativsystemer
#### Askil Amundøy Olsen: 473152

**Del 1:**
Kompilerer programmet med: 'gcc -Wall -o oblig del1_fork oblig_del1_fork.c'
Kjører programmet med: './oblig_del1_fork'
Output fra programmet ligger i 'del1_output.txt.' 
Dette er laget med './oblig_del1_fork > del1_output.txt'

Kvalitetssjekker
Brukt følgende
> cppcheck, clang-tidy5.0 og valgrind

utføres slik:

- Sjekk 1:
> cppcheck --enable=all ./oblig_del1_fork.c

*Får tilbakemelding at cppcheck ikke finner include files og at jeg skal bruke --check-config
cpp --check-config ./oblig_del1_fork.c gir beskjed om at include files ikke er lagt inn
Velger å gå til neste sjekk ettersom includefiles er lagt inn.*

- Sjekk 2:
> clang-tidy-5.0 -checks=\'*'\ oblig_del1_fork.c -- -std=c11

*Returnerer at include files ikke er sortert riktig*

- Sjekk 3:
> valgrind --leak-check=yes ./oblig_del1_fork

*Gir 0 errors*

- Sjekk 4:
> valgrind --tool=helgrind ./oblig_del1_fork

*Gir 0 errors*


**Del2:**
kompilerer med: 'gcc -Wall -pthread -o oblig_del2_pthreads oblig_del2_pthreads.c'
Kjører med './oblig_del2_pthreads'
Output ligger i 'del2_output.txt'
Dette er laget med './oblig_del2_pthreads > del2_output.txt'

kvalitetssjekker
Brukt følgende
> cppcheck, clang-tidy5.0 og valgrind

- Sjekk 1:
> cppcheck --enable=all ./oblig_del2_pthreads.c

*Gir tilbakemelding om at includefiles ikke er lagt inn*

- Sjekk 2:
> clang-tidy-5.0 -checks=\'*'\ oblig_del2_pthreads.c -- -std=c11

*Gir tilbakemelding om at for løkken burde være inni brackets, som den her*

- Sjekk 3:
> valgrind --leak-check=yes ./oblig_del2_pthreads

*Gir 1 error: definitely lost 192 bytes in 6 blocks
klarer ikke finne årsaken*

- Sjekk 4:
> valgrind --tool=helgrind ./oblig_del2_pthreads

*Gir 0 errors*


**Del 3:**

kompilerer med: 
'gcc -Wall -pthread -o oblig_del3_producerconsumer oblig_del3_producerconsumer.c'
Kjører med './oblig_del3_producerconsumer <Tallverdi for antall producers/consumers>'
Output ligger i 'del3_output.txt'
Dette er laget med './oblig_del3_producerconsumer 2 > del3_output.txt'

kvalitetssjekker
Brukt følgende
> cppcheck, clang-tidy5.0 og valgrind

- Sjekk 1:
> cppcheck --enable=all ./oblig_del3_producerconsumer.c

*Gir tilbakemelding om at "the scope of variable n, j, j can be reduced"*  

- Sjekk 2:
> clang-tidy-5.0 -checks=\'*'\ oblig_del3_producerconsumer.c -- -std=c11

*Gir 6 advarsler*

- Sjekk 3:
> valgrind --leak-check=yes ./oblig_del3_producerconsumer

*Gir 0 errors*

- Sjekk 4:
> valgrind --tool=helgrind ./oblig_del1_fork

*Gir 0 errors*



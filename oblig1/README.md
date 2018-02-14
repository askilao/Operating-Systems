# Oblig 1 IMT2282 Operativsystemer
#### Askil Amundøy Olsen: 473152

##### NB! diningphilosophers er ikke ment som en del av innleveringen, de 3 andre er oppgavene er det.
##### Del 1: <br>
Kompilerer programmet med: <br>
`gcc -Wall -o oblig del1_fork oblig_del1_fork.c`<br>
Kjører programmet med: <br>
`./oblig_del1_fork`<br>
Output fra programmet ligger i 'del1_output.txt.' <br>
Dette er laget med <br>
`./oblig_del1_fork > del1_output.txt`<br>

**Kvalitetssjekker** <br>
Brukt følgende
> cppcheck, clang-tidy5.0 og valgrind

utføres slik:<br>

- Sjekk 1:<br>
`cppcheck --enable=all ./oblig_del1_fork.c`<br>

*Får tilbakemelding at cppcheck ikke finner include files og at jeg skal bruke --check-config
cpp --check-config ./oblig_del1_fork.c gir beskjed om at include files ikke er lagt inn
Velger å gå til neste sjekk ettersom includefiles er lagt inn.*<br>

- Sjekk 2:<br>
`clang-tidy-5.0 -checks='*' oblig_del1_fork.c -- -std=c11`<br>
*Returnerer at include files ikke er sortert riktig*<br>

- Sjekk 3:<br>
`valgrind --leak-check=yes ./oblig_del1_fork`<br>
*Gir 0 errors*<br>

- Sjekk 4:<br>
`valgrind --tool=helgrind ./oblig_del1_fork`<br>
*Gir 0 errors*<br>


##### Del2:<br>
kompilerer med: <br>
`gcc -Wall -pthread -o oblig_del2_pthreads oblig_del2_pthreads.c`<br>
Kjører med <br>
`./oblig_del2_pthreads`<br>
Output ligger i 'del2_output.txt'<br>
Dette er laget med <br>
`./oblig_del2_pthreads > del2_output.txt` <br>

**kvalitetssjekker** <br>
Brukt følgende <br>
`cppcheck, clang-tidy5.0 og valgrind` <br>

- Sjekk 1: <br>
`cppcheck --enable=all ./oblig_del2_pthreads.c` <br>
*Gir tilbakemelding om at includefiles ikke er lagt inn* <br>

- Sjekk 2: <br>
`clang-tidy-5.0 -checks='*' oblig_del2_pthreads.c -- -std=c11`<br>
*Gir tilbakemelding om at for løkken burde være inni brackets, som den her*<br>

- Sjekk 3: <br>
`valgrind --leak-check=yes ./oblig_del2_pthreads` <br>
*Gir 1 error: definitely lost 192 bytes in 6 blocks
klarer ikke finne årsaken*<br>

- Sjekk 4:<br>
`valgrind --tool=helgrind ./oblig_del2_pthreads`<br>
*Gir 0 errors*<br>


##### Del 3: <br>
kompilerer med: <br>
`gcc -Wall -pthread -o oblig_del3_producerconsumer oblig_del3_producerconsumer.c` <br>
Kjører med <br>
`./oblig_del3_producerconsumer <Tallverdi for antall producers/consumers>` <br>
Output ligger i 'del3_output.txt'<br>
Dette er laget med <br>
`./oblig_del3_producerconsumer 2 > del3_output.txt`<br>

**Kvalitetssjekker** <br>
Brukt følgende
> cppcheck, clang-tidy5.0 og valgrind

- Sjekk 1: <br>
`cppcheck --enable=all ./oblig_del3_producerconsumer.c` <br>
*Gir tilbakemelding om at "the scope of variable n, j, j can be reduced"* <br>  

- Sjekk 2: <br>
`clang-tidy-5.0 -checks='*' oblig_del3_producerconsumer.c -- -std=c11` <br>
*Gir 6 advarsler*<br>

- Sjekk 3: <br>
`valgrind --leak-check=yes ./oblig_del3_producerconsumer` <br>
*Gir 0 errors* <br>

- Sjekk 4: <br>
`valgrind --tool=helgrind ./oblig_del1_fork`<br>
*Gir 0 errors* <br>



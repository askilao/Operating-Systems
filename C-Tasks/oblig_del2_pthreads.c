#include <stdio.h>		 /* printf */
#include <stdlib.h>		/* exit */
#include <unistd.h>		/* fork */
#include <pthread.h> 
#include <semaphore.h> 

#define SHARED 0
#define THREADS 6
sem_t sem[THREADS];

// En datastruktur til å gi info til trådene
struct threadargs {
	int id;         // Trådens ID
	int sec;        // Hvor lenge skal tråden kjøres
	int signal[THREADS];  // Hvem skal tråden gi signal til
                  // når den er ferdig?
};

void* tfunc(void *arg) {
		int i;
		struct threadargs *targs=arg;
  // Vent på lov til å kjøre (tell ned egen semafor)
  sem_wait(&sem[targs->id]);	
  // Print at tråden starter
  printf("Hei. Tråd %d har startet\n", targs->id);
  printf("Den skal kjøre i %d sekund\n", targs->sec);
  // Vent noen sekunder
  sleep(targs->sec);
  // Print at tråden er ferdig
  printf("Tråd %d ferdig\n", targs->id);
  // For i in 0->5:
	for(i=0; i<THREADS; i++){
      // Hvis "jeg" skal signalisere i:
		if(targs->signal[i]) {	
          // Tell opp semafor til tråd i
			sem_post(&sem[i]);
		}			
			
	}
	return 0;
}

int main(void) {
  int i, j;                    // Tellere til løkker
  struct threadargs* targs[THREADS]; // Pekere til argumentene vi gir til trådene.
  pthread_t tid[THREADS];            // Variabler til å holde trådinformasjon




  // Initialiser argumentene vi gir til trådene.
  for(j = 0; j < THREADS; j++) {
    targs[j] = malloc(sizeof(struct threadargs)); // Sett av minne, og
    targs[j]->id = 0;                             // sett alle variablene
    targs[j]->sec = 0;                            // til 0.
    for(i = 0; i < 6; i++)
      targs[j]->signal[i] = 0;
  }
  
  // START T0
  // Sett opp data til T0
  targs[0]->id = 0;
  targs[0]->sec = 1;
  targs[0]->signal[1] = 1;
  targs[0]->signal[4] = 1;
  // Initialiser semafor til T0
  sem_init(&sem[0], SHARED, 1);
  // Start T0
  pthread_create(&tid[0], NULL, tfunc, targs[0]);

  // START T1
  // Sett opp data til T1
  targs[1]->id = 1;
  targs[1]->sec = 2;
  targs[1]->signal[3] = 1;
  // Initialiser semafor til T1
  sem_init(&sem[1], SHARED, 0);
  // Start T1
  pthread_create(&tid[1], NULL, tfunc, targs[1]);


  // START T2
    targs[2]->id = 2;
    targs[2]->sec = 3;  
    //targs[2]->signal[3] = 1;
    
    sem_init(&sem[2], SHARED, 1);
    pthread_create(&tid[2], NULL, tfunc, targs[2]);
	
	//Starting thread 3
	targs[3]->id = 3;
	targs[3]->sec = 2;
	
	sem_init(&sem[3], SHARED, 0);
	pthread_create(&tid[3], NULL, tfunc, targs[3]);
	
	//Starting thread 4
	targs[4]->id = 4;
	targs[4]->sec = 3;
	targs[4]->signal[5] = 1;	
	
	sem_init(&sem[4], SHARED, 0);

	pthread_create(&tid[4], NULL, tfunc, targs[4]);
	
	//Starting thread 5
	targs[5]->id = 5;
	targs[5]->sec = 3;
	
	sem_init(&sem[5], SHARED, 0);
	pthread_create(&tid[5], NULL, tfunc, targs[5]);	
	
	
	//Ending all threads
	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
	pthread_join(tid[2], NULL);
	pthread_join(tid[3], NULL);
	pthread_join(tid[4], NULL);
	pthread_join(tid[5], NULL);

	
	return 0;
}



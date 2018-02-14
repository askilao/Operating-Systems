#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>     /* usleep */
#include <pthread.h>
#include <semaphore.h>

#define N 5 //Number of philosophers
#define LEFT (i+N-1)%N //number of is left neighbour
#define RIGHT (i+1)%N //Number of is right neighbour
#define THINKING 0 //number of thinking philosophers  
#define HUNGRY 1 //philosophers trying to get forks
#define EATING 2 //Philosphers is eating

typedef int semaphore;
int state[N];
int phil[N] = {0,1,2,3,4};
sem_t mutex;
sem_t s[N]; /* semaphores are a special kind of int */

void* philosopher(void *i);
void take_forks(int i);
void put_forks(int i);
void test(int i);

int main(){
		int i;
		pthread_t pid[N];

		sem_init(&mutex, 0, 1);

		for (i = 0; i<N; i++) {
			sem_init(&s[i],0,0);
		}
		
		for(i=0; i<N; i++) {
			pthread_create(&pid[i], NULL, philosopher, &phil[i]);		
			
			printf("Philosopher %d is thinking\n", i+1);
		}
		
		for(i=0; i<N; i++) {
			pthread_join(pid[i], NULL);
		}


}


void* philosopher(void* i)
{		
		int* num = i;
		while (1) {
				sleep(1);
				take_forks(*num);
				sleep(1);
				put_forks(*num);
		}
} /* i: philosopher number, from 0 to N−1 */
void take_forks(int i)
{
		sem_wait(&mutex);
		state[i] = HUNGRY;
		printf("Philospher %d is hungry\n", i+1);
		test(i);
		sem_post(&mutex);
		sem_wait(&s[i]);
} /* i: philosopher number, from 0 to N−1 */
void put_forks(int i)
{
		sem_wait(&mutex);
		state[i] = THINKING;

		printf("Philospher %d is putting fork %d and %d down\n", i+1, LEFT+1, i+1);
		printf("Philospher %d is thinking \n", i+1);
		test(LEFT);
		test(RIGHT);
		sem_post(&mutex);
}
void test(int i) /* i: philosopher number, from 0 to N−1 */
{
		if (state[i] == HUNGRY 
			&& state[LEFT] != EATING 
			&& state[RIGHT] != EATING) {
			state[i] = EATING;
			sleep(2);

			printf("Philospher %d takes fork %d and %d\n", i+1, LEFT+1, i+1);
			printf("Philosopher %d is eating\n", i+1);
			sem_post(&s[i]);
		}
}


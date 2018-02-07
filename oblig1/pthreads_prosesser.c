#include<stdio.h>
#include<stdlib.h>/*exit */
#include<unistd.h>/*fork */
#include<sys/wait.h>/*waitpid */
#include<sys/types.h>
#include<pthread.h>

static const int THREADS = 6;

struct ProcessArg{
	int id;
	int sec;
	int signal[THREADS];
	};


void* tfunc (void *arg) {
	
	struct  ProcessArg *targs=arg;
	printf("Prosess %d kjorer\n", targs->sec);
	printf("Prosess %d skal kjore i %d sekunder\n", targs->id, targs->sec);
	sleep(targs->sec);
	printf("Prosess %d er ferdig", targs->id);
		

	}


int main(void) {
	int i;
	pthread_t thread[THREADS];
	struct ProcessArg *args[THREADS];
	
	for(i=0; i<THREADS; i++){
		args[i] = (struct ProcessArg*) malloc(sizeof(struct processArg));
		}
	*arg[0].number = 0;
	*arg[0].time = 2;
	pthread_create(thread[0],NULL,process, (void*) args);
	pthread_join(thread[0], NULL);
	
return 0;
}	

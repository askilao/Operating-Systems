#include<stdio.h>
#include<stdlib.h>/*exit */
#include<unistd.h>/*fork */
#include<sys/wait.h>/*waitpid */
#include<sys/types.h>

void process(int number, int time) {
printf("Prosess %d kjorer\n", number);
sleep(time);
printf("Prosess %d kjorte i %d sekunder\n", number, time);
}

int main(void) {
pid_t pid[6]; //array of process 6 process ids

//Start process 0 and 2
pid[0] = fork();
if(pid[0] ==0){
	process(0,1);
	exit(0);
	}
pid[2] = fork();
if(pid[2] ==0){
	process(2,3);
	exit(0);
	}
//Wait for process 0 to finish
waitpid(pid[0],NULL,0);

//Start process 1
pid[1] = fork();
if(pid[1] ==0) {
	process(1,2);
	exit(0);
	}
//wait for proess 0 to finish
waitpid(pid[0],NULL,0);

//Start process 4
pid[4] = fork();
if(pid[4] ==0){
	process(4,3);
	exit(0);
	}
//wait for process 2 to finish
waitpid(pid[1],NULL,0);

//Start process 3
pid[3] = fork();
if(pid[3] ==0){
	process(3,2);
	exit(0);
	}
//Wait for process 4 to finish
waitpid(pid[4],NULL,0);

//Start process 5
pid[5] = fork();
if(pid[5] ==0){
	process(5,3);
	exit(0);
	}
//wait for the last process to finish and exit
waitpid(pid[5],NULL,0);
exit(0);
return 0;
}
	

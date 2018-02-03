#include<stdio.h>
#include<stdlib.h>/*exit */
#include<unistd.h>/*fork */
#include<sys/wait.h>/*waitpid */
#include<sys/types.h>

#define PARENT pid > 0
#define CHILD pid == 0

static int const PROCESSES = 6;

void process(int number, int time) {
printf("Prosess %d kjører\n", number);
sleep(time);
printf("Prosess %d kjørte i %d sekunder\n", number, time);
}

int main(void) {


pid_t pid, pid1,pid2;

pid = fork();
if(pid ==0){
	process(0,1);
}
else{
	process(2,3);
	exit(0);
}	

pid1 = fork();
if(pid1 ==0){
	process(1,2);
	}
else{
	process(4,3);
	exit(0);
	}

pid2 = fork();
if(pid2 ==0){
	waitpid(pid1,NULL,0);
	process(5,3);	
	
}	
else {
	process(3,2);
	exit(0);
}
return 0;
}
	

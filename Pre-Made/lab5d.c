#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>


int g_ant = 0;
 /* global declaration */
 void *writeloop(void *arg) {
	 long i = 0;
	 while (g_ant < 30) {
		 if (++i % 1000000 == 0)
			 printf("%s: %d\n", (char*) arg, ++g_ant);
	 }
	 exit(0);
 }
 int main(void)
 {
	 pthread_t tid;
	 pthread_create(&tid, NULL, writeloop, "2nd thread");
	 writeloop("1st thread");
	 pthread_join(tid, NULL);
	 return 0;
 }
 

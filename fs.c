#include<sys/types.h>
#include<sys/ipc.h>			//inter process communication
#include<sys/shm.h>			//shared memory functions
#include<stdio.h>				
#include<stdlib.h>			//exit
#include<unistd.h>			//sleep function
#include<sys/wait.h>
#define SHMSZ 27
void main()
{

int pid;

pid=fork();

if(pid==0){

int shmid;
key_t key;
int *shm, *s;

key = 5678;

if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) {		//other than 0666 you get denied error   and 0666 is used to give access to create a shm
									//in the shmget function ,an initial 0 indicates octal notation,owner,group,other
perror("shmget");
exit(1);}

if ((shm = shmat(shmid, NULL, 0)) == (int *) -1) {                   //shmaddr=null so the os takes the addr automaticaly
perror("shmat");
exit(1);
}

int sum=100;
s = shm;
*s=sum;
printf("sum in child process %d\n",*s);

}

else if(pid>0)
{
wait(NULL);
int shmid;
key_t key;
int *shm, *s;

key = 5678;
printf("Inside parent\n");
if ((shmid = shmget(key, SHMSZ, 0666)) < 0) {
perror("shmget");
exit(1);
}

if ((shm = shmat(shmid, NULL, 0)) == (int *) -1) {
perror("shmat");
exit(1);
}

s=shm;
printf("%d\n",*s);


exit(0);
}

}


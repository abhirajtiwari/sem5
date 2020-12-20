#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/sem.h>

#define PERM 0660

int semId;

int initSem(int id, int num, int initVal)
{
	return semctl(id, num, SETVAL, initVal);
}

int P(int id, int num)
{
	struct sembuf operationList[1];
	operationList[0].sem_num = num;
	operationList[0].sem_op = -1;
	operationList[0].sem_flg = 0;
	return semop(id, operationList, 1);
}

int V(int id, int num)
{
	struct sembuf operationList[1];
	operationList[0].sem_num = num;
	operationList[0].sem_op = 1;
	operationList[0].sem_flg = 0;
	return semop(id, operationList, 1);
}


void* func1(void* no)
{
	printf("Thread A trying to lock 0...\n");
	P(semId, 0);
	printf("Thread A locked 0.\n");
	usleep(5 * 1000);
	printf("Thread A trying to lock 1...\n");
	P(semId, 1);
	printf("Thread A locked 1.\n");
	V(semId, 0);
	V(semId, 1);
}


void* func2(void* no)
{
	printf("Thread B trying to lock 1...\n");
	P(semId, 1);
	printf("Thread B locked 1.\n");
	usleep(50 * 1000);
	printf("Thread B trying to lock 0...\n");
	P(semId, 0);
	printf("Thread B locked 0.\n");
	V(semId, 0);
	V(semId, 1);
}


int main(int argc, char* argv[])
{
	semId = semget(ftok(argv[0], 'A'), 2, IPC_CREAT | PERM);
	initSem(semId, 0, 1);
	initSem(semId, 1, 1);

	pthread_t t[2];
	pthread_create(&t[0], NULL, func1, NULL);
	pthread_create(&t[1], NULL, func2, NULL);
	for (int i = 0 ; i < 2 ; i++)
		pthread_join(t[i], NULL);

	printf("This is not printed in case of deadlock\n");
	semctl(semId, 0, IPC_RMID, 0);
	semctl(semId, 1, IPC_RMID, 0);
	return 0;
}
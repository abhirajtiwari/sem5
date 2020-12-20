#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

int buf[10], f=0, r=0, value;
sem_t mutex, full, empty;

void * produce(void * arg)
{
    for (int i=0;i<20;i++)
    {
        sem_wait(&empty);
        sem_wait(&mutex);
        printf("Produced item: %d\n",i);
        buf[(++r)%10]=i;
        sleep(1);
        sem_post(&mutex);
        sem_post(&full);
        sem_getvalue(&full, &value);
        printf("Value: %d\n", value);
    }
}

void * consume(void * arg)
{
    int item;
    for (int i=0;i<20;i++)
    {
        sem_wait(&full);
        sem_getvalue(&full, &value);
        printf("Value: %d\n", value);
        sem_wait(&mutex);
        item=buf[(++f)%10];
        printf("Consumed item: %d\n",item);
        sleep(1);
        sem_post(&mutex);
        sem_post(&empty);
    }
}

void main()
{
    pthread_t t1,t2;
    sem_init(&mutex, 0, 1);
    sem_init(&full, 0, 1);
    sem_init(&empty, 0, 10);
    pthread_create(&t1, NULL, produce, NULL);
    pthread_create(&t2, NULL, consume, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
}
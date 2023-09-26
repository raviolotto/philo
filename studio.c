#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

int primes[10] = { 2, 3, 7, 9, 11, 13, 17, 19, 23, 29};
pthread_mutex_t mutex;

void* routine(void *arg)
{
	pthread_mutex_lock(&mutex);
	int current;
	current = (*(int*)arg) - 1;
	pthread_mutex_unlock(&mutex);
	return (void*) &primes[current];
}

int main(int ac, char** argv)
{
	int *prime;
	int i;

	i = 0;
	pthread_t th[10];
	pthread_mutex_init(&mutex, NULL);
	while(i < 10)
	{
		if (pthread_create(th + i, NULL, &routine, &i) != 0){
			return(1);
		}
		i++;
	}
	sleep(1);
	i = 0;
	while (i < 10)
	{
		if (pthread_join(th[i], (void**) &prime) != 0){
			return(2);
		}
		printf("res = %d\n", *prime);
		i++;
	}
	pthread_mutex_destroy(&mutex);
	return(0);
}


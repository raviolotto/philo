#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

void* routine()
{
	int value = (rand() % 6) + 1;
	printf("%d\n", value);
}

int main(int ac, char** argv)
{
	pthread_t th;
	srand(time(NULL));
	pthread_create(&th, NULL, &routine, NULL);
	pthread_join(th, NULL);
	return

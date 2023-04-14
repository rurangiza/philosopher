#include <stdio.h>
#include <pthread.h>
#include<stime.h>

#define THREAD_NUM 8
pthread_mutex_t	mutexFuel;
int	fuel = 50;

void	*routine(void *args)
{	
	pthread_mutex_lock(mutexFuel);
	fuel += 50;
	pthread_mutex_unlock(&mutexFuel);
}

int main(void)
{
	pthread_t	th[THREAD_NUM];
	pthread_mutex_init(&mutexFuel, NULL);
	
	int	i;
	for (i = 0; i < THREAD_NUM; i++)
	{
		if (pthread_create(&th[i], NULL, &routine, NULL) !=0)
			perror("Failed to create thread");
	}
	for (i = 0; i < THREAD_NUM; i++)
	{
		if (pthread_join(th[i], NULL) != 0)
			perror("Failed to join thread");
	}
	pthread_mutex_destroy(&mutexFuel);
	return (0);
}

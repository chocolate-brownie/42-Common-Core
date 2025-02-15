#include "../include/philo.h"

void	debug_print_setup(t_setup *setup)
{
	printf("\n=== Setup Configuration ===\n");
	printf("Number of philosophers: %u\n", setup->phils);
	printf("Time to die: %u ms\n", setup->time_to_die);
	printf("Time to eat: %u ms\n", setup->time_to_eat);
	printf("Time to sleep: %u ms\n", setup->time_to_sleep);
	printf("\n=== Initial State ===\n");
	printf("Start time: %ld.%06ld\n", setup->start.tv_sec,
		setup->start.tv_usec);
	printf("Death status: %s\n", setup->died ? "true" : "false");
	printf("Full philosophers: %u\n", setup->fulled_phils);
	printf("\n=== Last Meal Times ===\n");
	for (unsigned int i = 0; i < setup->phils; i++)
	{
		printf("Philosopher %u last meal: %ld.%06ld\n", i + 1,
			setup->last_meal[i].tv_sec, setup->last_meal[i].tv_usec);
	}
	printf("\n=== Mutex Verification ===\n");
	printf("Fork mutexes allocated: %s\n", setup->mtx_fork ? "Yes" : "No");
	printf("Full mutex allocated: %s\n", setup->mtx_full ? "Yes" : "No");
	printf("Dead mutex allocated: %s\n", setup->mtx_dead ? "Yes" : "No");
	printf("Meal mutex allocated: %s\n", setup->mtx_meal ? "Yes" : "No");
	printf("Print mutex allocated: %s\n", setup->mtx_print ? "Yes" : "No");
	printf("\n");
	printf("\n");
}


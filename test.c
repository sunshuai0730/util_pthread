/**
 * @file test.c
 * @author 余王亮 (wotsen@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2019-11-02
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <unistd.h>
#include "util_pthread.h"

void *test(void *arg)
{
	set_thread_name("test");
	while (1)
	{
		printf("..................\n");
		sleep(3);
	}
}

int main(void)
{
	pthread_t tid;

	if (create_thread(&tid, PTHREAD_STACK_MIN, SYS_THREAD_PRI_LV, test, NULL))
	{
		printf("create %zu success\n", tid);
	}

	while (1);

	return 0;
}
/**
 * @file util_pthread.h
 * @author 余王亮 (wotsen@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2019-11-02
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef __UTIL_PTHREAD_H__
#define __UTIL_PTHREAD_H__

#include <pthread.h>
#include <stdio.h>
#include <stdbool.h>

#define INVALID_PTHREAD_TID -1

///< 线程名最长长度
#define MAX_THREAD_NAME_LEN 15

///< 栈长度，传入数字以k为单位
#define STACKSIZE(k) ((k)*1024)

///< 最小栈
#ifndef PTHREAD_STACK_MIN
	#define PTHREAD_STACK_MIN 16384
#endif

#define MAX_THREAD_PRI_LV	100
#define SYS_THREAD_PRI_LV	90
#define RUN_THREAD_PRI_LV	80
#define FUN_THREAD_PRI_LV	70
#define THR_THREAD_PRI_LV	60
#define MIN_THREAD_PRI_LV	50

///< 线程毁掉接口
typedef void *(*thread_func)(void *);

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

///< 创建线程
bool create_thread(pthread_t *tid, const size_t stacksize, const int priority, thread_func fn, void *arg);

///< 设置线程名
void set_thread_name(const char *name);

///< 释放线程
bool release_thread(const pthread_t tid);

///< 检测线程存活
bool if_thread_exsit(const pthread_t tid);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // !__UTIL_PTHREAD_H__
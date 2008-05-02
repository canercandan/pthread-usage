/*
** xpthread_mutex_init.c for philo1 in /home/candan_c/cu/rendu/project/philo1/test
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu May  1 10:21:07 2008 caner candan
** Last update Thu May  1 21:25:21 2008 caner candan
*/

#include <pthread.h>
#include <stdio.h>
#include "x.h"

int	xpthread_mutex_init(void *mutex, const void *attr)
{
  int	rc;

  if ((rc = pthread_mutex_init((pthread_mutex_t *) mutex,
			       (pthread_mutexattr_t *) attr)) < 0)
    perror("pthread_mutex_init");
  return (rc);
}

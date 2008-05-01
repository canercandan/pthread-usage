/*
** xpthread_mutex_trylock.c for philo1 in /home/candan_c/cu/rendu/project/philo1/test
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu May  1 10:31:32 2008 caner candan
** Last update Thu May  1 10:33:15 2008 caner candan
*/

#include <pthread.h>
#include <stdio.h>
#include "x.h"

int	xpthread_mutex_trylock(void *mutex)
{
  int	rc;

  if ((rc = pthread_mutex_trylock((pthread_mutex_t *) mutex)) != 0)
    perror("pthread_mutex_trylock");
  return (rc);
}

/*
** xpthread_mutex_unlock.c for philo1 in /home/candan_c/cu/rendu/project/philo1/test
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu May  1 10:33:45 2008 caner candan
** Last update Thu May  1 10:35:15 2008 caner candan
*/

#include <pthread.h>
#include <stdio.h>
#include "x.h"

int	xpthread_mutex_unlock(void *mutex)
{
  int	rc;

  if ((rc = pthread_mutex_unlock((pthread_mutex_t *) mutex)) != 0)
    perror("pthread_mutex_unlock");
  return (rc);
}

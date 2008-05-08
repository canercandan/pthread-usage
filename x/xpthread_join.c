/*
** xpthread_join.c for philo1 in /home/candan_c/cu/rendu/project/philo1/test
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu May  1 11:22:26 2008 caner candan
** Last update Thu May  8 18:00:04 2008 caner candan
*/

#include <pthread.h>
#include <stdio.h>
#include "x.h"

int	xpthread_join(void *thread, void **value_ptr)
{
  int	rc;

  if ((rc = pthread_join(PTHREAD_VALUE(thread), value_ptr)) < 0)
    perror("pthread_join");
  return (rc);
}

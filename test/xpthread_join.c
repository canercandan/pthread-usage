/*
** xpthread_join.c for philo1 in /home/candan_c/cu/rendu/project/philo1/test
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu May  1 11:22:26 2008 caner candan
** Last update Thu May  1 11:26:39 2008 caner candan
*/

#include <pthread.h>
#include <stdio.h>
#include "x.h"

int	xpthread_join(void *pthread, void **value_ptr)
{
  int	rc;

  if ((rc = pthread_join((pthread_t) pthread, value_ptr)) != 0)
    perror("pthread_join");
  return (rc);
}

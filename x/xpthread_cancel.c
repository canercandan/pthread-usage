/*
** xpthread_cancel.c for philo1 in /home/candan_c/cu/rendu/project/philo1
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu May  8 14:55:10 2008 caner candan
** Last update Thu May  8 18:00:52 2008 caner candan
*/

#include <pthread.h>
#include <stdio.h>
#include "x.h"

int	xpthread_cancel(void *thread)
{
  int	rc;

  if ((rc = pthread_cancel(PTHREAD_VALUE(thread))) < 0)
    perror("pthread_cancel");
  return (rc);
}

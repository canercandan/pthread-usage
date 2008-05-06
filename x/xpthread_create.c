/*
** xpthread_create.c for philo1 in /home/candan_c/cu/rendu/project/philo1/test
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu May  1 10:11:58 2008 caner candan
** Last update Tue May  6 15:05:24 2008 caner candan
*/

#include <pthread.h>
#include <stdio.h>
#include "x.h"

int	xpthread_create(void *thread, const void *attr,
			void *(*start_routine)(void *), void *arg)
{
  int	rc;

  if ((rc = pthread_create(PTHREAD(thread), PTHREAD_ATTR(attr),
			   start_routine, arg)) < 0)
    perror("pthread_create");
  return (rc);
}

/*
** xpthread_mutex_destroy.c for philo1 in /home/candan_c/cu/rendu/project/philo1/test
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu May  1 10:27:15 2008 caner candan
** Last update Sun May 11 11:19:29 2008 florent hochwelker
*/

#include <pthread.h>
#include <stdio.h>
#include "my.h"
#include "x.h"

int	xpthread_mutex_destroy(void *mutex)
{
  int	rc;

  if ((rc = pthread_mutex_destroy(PTHREAD_MUTEX(mutex))) != 0)
    perror("pthread_mutex_destroy");
  return (rc);
}

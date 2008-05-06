/*
** xpthread_cond_wait.c for philo1 in /home/candan_c/cu/rendu/project/philo1/test
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Fri May  2 09:38:56 2008 caner candan
** Last update Tue May  6 15:09:18 2008 caner candan
*/

#include <pthread.h>
#include <stdio.h>
#include "x.h"

int	xpthread_cond_wait(void *cond, void *mutex)
{
  int	rc;

  if ((rc = pthread_cond_wait(PTHREAD_COND(cond), PTHREAD_MUTEX(mutex))) < 0)
    perror("pthread_cond_wait");
  return (rc);
}

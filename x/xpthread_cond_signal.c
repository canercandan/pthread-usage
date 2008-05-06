/*
** xpthread_cond_signal.c for philo1 in /u/epitech_2010s/candan_c/cu/rendu/c/philo1/test
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Fri May  2 10:08:14 2008 caner candan
** Last update Tue May  6 15:08:54 2008 caner candan
*/

#include <pthread.h>
#include <stdio.h>
#include "x.h"

int	xpthread_cond_signal(void *cond)
{
  int	rc;

  if ((rc = pthread_cond_signal(PTHREAD_COND(cond))) < 0)
    perror("pthread_cond_signal");
  return (rc);
}

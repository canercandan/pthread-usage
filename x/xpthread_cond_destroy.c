/*
** xpthread_cond_destroy.c for philo1 in /u/epitech_2010s/candan_c/cu/rendu/c/philo1/test
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Fri May  2 11:15:36 2008 caner candan
** Last update Tue May  6 15:07:23 2008 caner candan
*/

#include <pthread.h>
#include <stdio.h>
#include "x.h"

int	xpthread_cond_destroy(void *cond)
{
  int	rc;

  if ((rc = pthread_cond_destroy(PTHREAD_COND(cond))) < 0)
    perror("pthread_cond_destroy");
  return (rc);
}

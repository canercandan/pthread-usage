/*
** xpthread_cond_init.c for philo1 in /home/candan_c/cu/rendu/project/philo1/test
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Fri May  2 09:36:41 2008 caner candan
** Last update Fri May  2 09:38:35 2008 caner candan
*/

#include <pthread.h>
#include <stdio.h>
#include "x.h"

int	xpthread_cond_init(void *cond, const void *attr)
{
  int	rc;

  if ((rc = pthread_cond_init((pthread_cond_t *) cond,
			      (pthread_condattr_t *) attr)) < 0)
    perror("pthread_cond_init");
  return (rc);
}
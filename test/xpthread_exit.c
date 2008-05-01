/*
** xpthread_exit.c for philo1 in /home/candan_c/cu/rendu/project/philo1/test
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu May  1 10:18:30 2008 caner candan
** Last update Thu May  1 10:19:11 2008 caner candan
*/

#include <pthread.h>
#include "x.h"

void	xpthread_exit(void *value_ptr)
{
  pthread_exit(value_ptr);
}

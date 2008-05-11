/*
** main.c for philo1 in /home/candan_c/cu/rendu/project/philo1
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Fri May  9 19:50:37 2008 caner candan
** Last update Sun May 11 11:55:01 2008 caner candan
*/

#include <pthread.h>
#include "philo1.h"

int		main(int ac, char **av)
{
  init_signal();
  parse_args(ac, av);
  create_thread(0);
  pthread_exit(NULL);
}

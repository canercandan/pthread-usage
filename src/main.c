/*
** main.c for philo1 in /home/candan_c/cu/rendu/project/philo1
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Fri May  9 19:50:37 2008 caner candan
** Last update Sat May 10 22:36:52 2008 caner candan
*/

#include <pthread.h>
#include "philo1.h"

int		main(int ac, char **av)
{
  t_info	info;

  init_signal(&info);
  parse_args(ac, av, &info);
  create_thread(0, &info);
  pthread_exit(NULL);
}

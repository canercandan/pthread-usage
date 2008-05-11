/*
** main.c for philo1 in /home/candan_c/cu/rendu/project/philo1
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Fri May  9 19:50:37 2008 caner candan
** Last update Sun May 11 11:28:04 2008 florent hochwelker
*/

#include <pthread.h>
#include "philo1.h"

int		main(int ac, char **av)
{
  t_info	info;

  init_signal(&info);
  parse_args(ac, av, &info);
  info.end = 0;
  create_thread(0, &info);
  pthread_exit(NULL);
}

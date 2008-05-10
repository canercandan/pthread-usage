/*
** parse_args.c for philo1 in /home/candan_c/cu/rendu/project/philo1
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sat May 10 21:25:43 2008 caner candan
** Last update Sat May 10 22:43:29 2008 caner candan
*/

#include <stdlib.h>
#include "philo1.h"
#include "my.h"

int	parse_args(int ac, char **av, t_info *info)
{
  if (ac == 2 && !my_strcmp(av[1], "-g"))
    {
      info->nb_philos = NB;
      info->nb_sticks = NB;
      if (init_sdl(info) < 0)
	return (-1);
    }
  if (ac == 3 && !my_strcmp(av[1], "-n"))
    {
      info->nb_philos = atoi(av[2]);
      info->nb_sticks = info->nb_philos;
      return (0);
    }
  if (ac == 5 && !my_strcmp(av[1], "-n") && !my_strcmp(av[3], "-s"))
    {
      info->nb_philos = atoi(av[2]);
      info->nb_sticks = atoi(av[4]);
      return (0);
    }
  else
    {
      info->nb_philos = NB;
      info->nb_sticks = NB;
    }
  return (0);
}

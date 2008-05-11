/*
** parse_args.c for philo1 in /home/candan_c/cu/rendu/project/philo1
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sat May 10 21:25:43 2008 caner candan
** Last update Sun May 11 15:21:35 2008 florent hochwelker
*/

#include <stdlib.h>
#include "philo1.h"
#include "my.h"

t_info	gl_info;

static int	with_graphic(int ac, char **av)
{
  if (ac == 2 && !my_strcmp(av[1], "-g"))
    {
      gl_info.nb_philos = NB;
      gl_info.nb_sticks = NB;
      gl_info.mode_gfx = 1;
      if (init_sdl() < 0)
	return (-1);
      return (0);
    }
  return (-1);
}

static int	mode_normal(int ac, char **av)
{
  if (ac == 3 && !my_strcmp(av[1], "-n"))
    {
      gl_info.nb_philos = atoi(av[2]);
      gl_info.nb_sticks = gl_info.nb_philos;
      gl_info.mode_gfx = 0;
      return (0);
    }
  return (-1);
}

int	parse_args(int ac, char **av)
{
  gl_info.end = 0;
  if (with_graphic(ac, av) < 0)
    if (mode_normal(ac, av) < 0)
      {
	gl_info.nb_philos = NB;
	gl_info.nb_sticks = NB;
	gl_info.mode_gfx = 0;
      }
  return (0);
}

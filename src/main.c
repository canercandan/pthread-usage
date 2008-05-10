/*
** main.c for philo1 in /home/candan_c/cu/rendu/project/philo1
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Fri May  9 19:50:37 2008 caner candan
** Last update Sat May 10 15:33:32 2008 florent hochwelker
*/

#include "philo1.h"
#include <unistd.h>

static int	init_sdl()
{
  t_gfx		gfx;

  if (init_screen(&gfx) < 0)
    return (-1);
  init_signal(&gfx);
  if (create_character(&gfx))
    return (-1);
  while (53)
    if (loop_env(&gfx) < 0)
      break;
  destroy_character(&gfx);
  destroy_screen(&gfx);
  return (0);
}

int	main(int ac, char **av)
{
  if (ac == 2 && !my_strcmp(av[1], "-g"))
    {
      if (init_sdl() < 0)
	return (-1);
      return (0);
    }
  else
    create_thread(0);
  return (0);
}

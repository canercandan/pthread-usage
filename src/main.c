/*
** main.c for philo1 in /home/candan_c/cu/rendu/project/philo1
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Fri May  9 19:50:37 2008 caner candan
** Last update Sat May 10 18:02:24 2008 caner candan
*/

#include "philo1.h"
#include <unistd.h>

static int	init_sdl()
{
  t_gfx		gfx;

  if (init_screen() < 0)
    return (-1);
  init_signal(&gfx);
  if (create_backdrop(&gfx) < 0)
    return (-1);
  if (create_video(&gfx) < 0)
    return (-1);
  if (create_character(&gfx))
    return (-1);
  if (create_status(&gfx) < 0)
    return (-1);
  while (53)
    if (loop_env(&gfx) < 0)
      break;
  destroy_surface(gfx.status);
  destroy_surface(gfx.character);
  destroy_surface(gfx.backdrop);
  destroy_surface(gfx.video);
  destroy_screen();
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

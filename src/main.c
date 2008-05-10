/*
** main.c for philo1 in /home/candan_c/cu/rendu/project/philo1
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Fri May  9 19:50:37 2008 caner candan
** Last update Sat May 10 19:17:09 2008 florent hochwelker
*/

#include <unistd.h>
#include <pthread.h>
#include "philo1.h"

static void	*sdl_powa(void *data)
{
  t_gfx		gfx;

  (void)data;
  if (init_screen() < 0)
    pthread_exit(NULL);
  init_signal(&gfx);
  if (create_backdrop(&gfx) < 0)
    pthread_exit(NULL);
  if (create_video(&gfx) < 0)
    pthread_exit(NULL);
  if (create_character(&gfx))
    pthread_exit(NULL);
  if (create_status(&gfx) < 0)
    pthread_exit(NULL);
  while (53)
    if (loop_env(&gfx) < 0)
      break;
  destroy_surface(gfx.status);
  destroy_surface(gfx.character);
  destroy_surface(gfx.backdrop);
  destroy_surface(gfx.video);
  destroy_screen();
  pthread_exit(NULL);
}

static int	init_sdl()
{
  pthread_t	threads;
  int		r;

  create_thread(0);
  if ((r = pthread_create(&threads, NULL, sdl_powa, NULL)))
    {
      my_putstr("Thread error\n");
      return (-1);
    }
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

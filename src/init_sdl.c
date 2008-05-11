/*
** init_sdl.c for philo1 in /home/candan_c/cu/rendu/project/philo1
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sat May 10 20:20:57 2008 caner candan
** Last update Sun May 11 12:09:36 2008 caner candan
*/

#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include "philo1.h"
#include "my.h"

t_info	gl_info;

static void	*sdl_powa(void *data)
{
  t_gfx		gfx;

  (void)data;
  if (init_screen() < 0 ||
      create_backdrop(&gfx) < 0 ||
      create_video(&gfx) < 0 ||
      create_character(&gfx) < 0 ||
      create_status(&gfx) < 0)
    pthread_exit(NULL);
  while (53)
    if (loop_env(&gfx) < 0)
      break;
  destroy_surface(gfx.status);
  destroy_surface(gfx.character);
  destroy_surface(gfx.backdrop);
  destroy_surface(gfx.video);
  destroy_screen();
  exit(0);
  pthread_exit(NULL);
}

int		init_sdl(void)
{
  pthread_t	threads;
  int		r;

  if ((r = pthread_create(&threads, NULL, sdl_powa, NULL)) < 0)
    {
      my_putstr("Thread error\n");
      return (-1);
    }
  create_thread(1);
  pthread_exit(NULL);
}

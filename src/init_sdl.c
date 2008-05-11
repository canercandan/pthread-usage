/*
** init_sdl.c for philo1 in /home/candan_c/cu/rendu/project/philo1
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sat May 10 20:20:57 2008 caner candan
** Last update Sun May 11 18:41:24 2008 caner candan
*/

#include <pthread.h>
#include "philo1.h"
#include "my.h"

t_info	gl_info;

static void	*sdl_powa(void *data)
{
  (void)data;
  if (init_screen() < 0 ||
      create_backdrop(&gl_info.gfx) < 0 ||
      create_video(&gl_info.gfx) < 0 ||
      create_character(&gl_info.gfx) < 0 ||
      create_status(&gl_info.gfx) < 0)
    pthread_exit(NULL);
  while (53)
    if (loop_env(&gl_info.gfx) < 0)
      break;
  power_off(0);
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
  create_thread(0);
  pthread_exit(NULL);
}

/*
** init_signal.c for philo1 in /home/candan_c/cu/rendu/project/philo1
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu May  8 15:03:15 2008 caner candan
** Last update Sat May 10 22:58:20 2008 caner candan
*/

#include <pthread.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "philo1.h"
#include "x.h"

static void	*signal_data = NULL;

static void	power_off(int signal)
{
  int		i;

  (void) signal;
  if (INFO(signal_data)->mode_gfx == 1)
    {
      destroy_surface(INFO(signal_data)->gfx.status);
      destroy_surface(INFO(signal_data)->gfx.character);
      destroy_surface(INFO(signal_data)->gfx.backdrop);
      destroy_surface(INFO(signal_data)->gfx.video);
      destroy_screen();
    }
  i = 0;
  while (i < INFO(signal_data)->nb_sticks)
    {
      xpthread_mutex_destroy(PTHREAD_MUTEX(gl_stick)[i]);
      i++;
    }
  free(gl_stick);
  free(gl_status);
  free(gl_hp);
  free(INFO(signal_data)->threads);
  write(1, PWR_OFF_MESG, strlen(PWR_OFF_MESG));
  exit(0);
}

void	init_signal(t_info *info)
{
  signal_data = info;
  signal(SIGINT, power_off);
}

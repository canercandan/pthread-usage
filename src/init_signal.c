/*
** init_signal.c for philo1 in /home/candan_c/cu/rendu/project/philo1
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu May  8 15:03:15 2008 caner candan
** Last update Sun May 11 11:32:29 2008 caner candan
*/

#include <pthread.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "philo1.h"
#include "x.h"
#include "my.h"

t_info	gl_info;

static void	power_off(int signal)
{
  int		i;

  (void) signal;
  /*   if (INFO(signal_data)->mode_gfx == 1) */
  /*     { */
  /*       destroy_surface(INFO(signal_data)->gfx.status); */
  /*       destroy_surface(INFO(signal_data)->gfx.character); */
  /*       destroy_surface(INFO(signal_data)->gfx.backdrop); */
  /*       destroy_surface(INFO(signal_data)->gfx.video); */
  /*       destroy_screen(); */
  /*     } */
  i = 0;
  while (i < gl_info.nb_sticks)
    {
      xpthread_mutex_destroy(&PTHREAD_MUTEX(gl_info.stick)[i]);
      i++;
    }
  free(gl_info.stick);
  free(gl_info.status);
  free(gl_info.hp);
  free(gl_info.threads);
  my_putstr(PWR_OFF_MESG);
  exit(0);
}

void	init_signal(void)
{
  signal(SIGINT, power_off);
}

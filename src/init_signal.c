/*
** init_signal.c for philo1 in /home/candan_c/cu/rendu/project/philo1
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu May  8 15:03:15 2008 caner candan
** Last update Sat May 10 12:16:17 2008 caner candan
*/

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "philo1.h"

static void	*signal_data = NULL;

static void	power_off(int signal)
{
  (void) signal;
  destroy_screen(signal_data);
  write(1, PWR_OFF_MESG, strlen(PWR_OFF_MESG));
  exit(0);
}

void	init_signal(t_gfx *gfx)
{
  signal_data = gfx;
  signal(SIGINT, power_off);
}

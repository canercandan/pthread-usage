/*
** init_signal.c for philo1 in /home/candan_c/cu/rendu/project/philo1
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu May  8 15:03:15 2008 caner candan
** Last update Sun May 11 15:34:06 2008 florent hochwelker
*/

#include <signal.h>
#include "philo1.h"

void	init_signal(void)
{
  signal(SIGINT, power_off);
}

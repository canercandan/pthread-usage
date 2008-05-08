/*
** launch_history.c for philo1 in /home/candan_c/cu/rendu/project/philo1
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu May  8 14:39:37 2008 caner candan
** Last update Thu May  8 17:58:40 2008 caner candan
*/

#include "philo1.h"
#include "x.h"

static void	launch_character(void **character, int limit)
{
  int		i;

  for (i = 0; i < limit; i++)
    xpthread_join(character[i], NULL);
}

void	launch_history(t_info *info)
{
  launch_character(info->philo, NB_PHILOS);
  launch_character(info->sticks, NB_STICKS);
  xpthread_join(info->eat.thread, NULL);
  xpthread_join(info->sleep.thread, NULL);
  xpthread_join(info->think.thread, NULL);
}

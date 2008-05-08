/*
** destroy_actors.c for philo1 in /home/candan_c/cu/rendu/project/philo1
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu May  8 14:51:08 2008 caner candan
** Last update Thu May  8 17:59:38 2008 caner candan
*/

#include "philo1.h"
#include "x.h"

static void	destroy_elm(t_thr *elm)
{
  xpthread_cancel(elm->thread);
  xpthread_mutex_destroy(&(elm->mutex));
  xpthread_cond_destroy(&(elm->cond));
}

static void	destroy_character(void **character, int limit)
{
  int		i;

  for (i = 0; i < limit; i++)
    xpthread_cancel(character[i]);
}

void	destroy_actors(t_info *info)
{
  destroy_elm(&(info->eat));
  destroy_elm(&(info->sleep));
  destroy_elm(&(info->think));
  destroy_character(info->philo, NB_PHILOS);
  destroy_character(info->sticks, NB_STICKS);
}

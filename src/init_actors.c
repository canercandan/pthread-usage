/*
** init_actors.c for philo1 in /home/candan_c/cu/rendu/project/philo1
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu May  8 14:22:26 2008 caner candan
** Last update Thu May  8 17:57:20 2008 caner candan
*/

#include "philo1.h"
#include "x.h"

static void	init_elm(t_thr *elm, t_info *info, void *(*f)(void *))
{
  xpthread_cond_init(&(elm->cond), NULL);
  xpthread_mutex_init(&(elm->mutex), NULL);
  xpthread_create(&(elm->thread), NULL, f, info);
}

static void	init_character(void **character, int limit,
			       t_info *info, void *(*f)(void *))
{
  int		i;

  for (i = 0; i < limit; i++)
    xpthread_create(character[i], NULL, f, info);
}

void	init_actors(t_info *info)
{
  init_elm(&(info->eat), info, NULL);
  init_elm(&(info->sleep), info, NULL);
  init_elm(&(info->think), info, NULL);
  init_character(info->philo, NB_PHILOS, info, NULL);
  init_character(info->sticks, NB_STICKS, info, NULL);
  xpthread_cond_init(&(info->cond_philo), NULL);
  xpthread_cond_init(&(info->cond_sticks), NULL);
}

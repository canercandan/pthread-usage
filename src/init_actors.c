/*
** init_actors.c for philo1 in /home/candan_c/cu/rendu/project/philo1
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu May  8 14:22:26 2008 caner candan
** Last update Fri May  9 16:34:52 2008 caner candan
*/

#include <unistd.h>
#include "philo1.h"
#include "x.h"

static void	*fct_null(void *data)
{
  (void) data;
  while (42)
    {
      write(1, "NULL\n", 5);
      sleep(1);
    }
  return (NULL);
}

static void	init_elm(t_thr *elm, t_info *info, void *(*f)(void *))
{
  xpthread_cond_init(&(elm->cond), NULL);
  xpthread_mutex_init(&(elm->mutex), NULL);
  xpthread_create(&(elm->thread), NULL, f, info);
}

static void	init_philos(t_info *info, int limit,
			    void *(*f)(void *))
{
  int		i;

  for (i = 0; i < limit; i++)
    xpthread_create(&(info->philo[i]), NULL, f, info);
}

static void	init_sticks(t_info *info, int limit,
			    void *(*f)(void *))
{
  int		i;

  for (i = 0; i < limit; i++)
    xpthread_create(&(info->stick[i]), NULL, f, info);
}

void	init_actors(t_info *info)
{
  init_elm(&(info->eat), info, fct_null);
  init_elm(&(info->sleep), info, fct_null);
  init_elm(&(info->think), info, fct_null);
  init_philos(info, NB_PHILOS, philo_running);
  init_sticks(info, NB_STICKS, stick_running);
  xpthread_cond_init(&(info->cond_philo), NULL);
  xpthread_cond_init(&(info->cond_sticks), NULL);
}

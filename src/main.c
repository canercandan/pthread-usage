/*
** main.c for philo1 in /home/candan_c/cu/rendu/project/philo1
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue May  6 15:45:45 2008 caner candan
** Last update Thu May  8 17:51:48 2008 caner candan
*/

#include <string.h>
#include <unistd.h>
#include "philo1.h"
#include "x.h"

/* static void	is_switch_on(int nb, void *tp) */
/* { */
/*   if (nb == CRITIC_MIN) */
/*     { */
/*       xpthread_mutex_lock(&TP(tp)->mutex_bridge); */
/*       xpthread_cond_signal(&TP(tp)->cond_bridge); */
/*       xpthread_cond_wait(&TP(tp)->cond_train, &TP(tp)->mutex_bridge); */
/*     } */
/* } */

/* static void	is_switch_off(int nb, void *tp) */
/* { */
/*   if (nb == CRITIC_MAX) */
/*     { */
/*       xpthread_cond_signal(&TP(tp)->cond_train); */
/*       xpthread_mutex_unlock(&TP(tp)->mutex_bridge); */
/*     } */
/* } */

/* static void	*on_way(void *tp) */
/* { */
/*   char		buf[WAY_SIZE + 1]; */
/*   int		i; */

/*   i = 0; */
/*   while (42) */
/*     { */
/*       if (i == WAY_SIZE - 2) */
/* 	i = 0; */
/*       is_switch_on(i, tp); */
/*       is_switch_off(i, tp); */
/*       strcpy(buf, WAY_FMT); */
/*       buf[i] = TRAIN; */
/*       write(1, buf, WAY_SIZE); */
/*       i++; */
/*       sleep(1); */
/*     } */
/*   return (NULL); */
/* } */

/* static void	*on_bridge(void *tp) */
/* { */
/*   xpthread_mutex_lock(&TP(tp)->mutex_bridge); */
/*   xpthread_cond_wait(&TP(tp)->cond_bridge, &TP(tp)->mutex_bridge); */
/*   xpthread_cond_signal(&TP(tp)->cond_train); */
/*   xpthread_mutex_unlock(&TP(tp)->mutex_bridge); */
/*   return (NULL); */
/* } */

int		main(void)
{
  t_info	info;

  init_signal(&info);
  init_actors(&info);
  launch_history(&info);
  destroy_actors(&info);
  return (0);
}

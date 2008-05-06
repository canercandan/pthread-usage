/*
** main2.c for tp in /home/candan_c/cu/rendu/project/philo1/tp
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue May  6 07:39:37 2008 caner candan
** Last update Tue May  6 14:56:28 2008 caner candan
*/

#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include "tp.h"

static void	*on_way(void *tp)
{
  char		buf[WAY_SIZE + 1];
  int		i;

  i = 0;
  while (42)
    {
      if (i == WAY_SIZE - 2)
	i = 0;
      if (i == CRITIC_MIN)
	{
	  pthread_mutex_lock(PTHREAD_MUTEX(&TP(tp)->mutex_bridge));
	  pthread_cond_signal(PTHREAD_COND(&TP(tp)->cond_bridge));
	  pthread_cond_wait(PTHREAD_COND(&TP(tp)->cond_train),
			    PTHREAD_MUTEX(&TP(tp)->mutex_bridge));
	}
      if (i == CRITIC_MAX)
	{
	  pthread_cond_signal(PTHREAD_COND(&TP(tp)->cond_train));
	  pthread_mutex_unlock(PTHREAD_MUTEX(&TP(tp)->mutex_bridge));
	}
      strcpy(buf, WAY_FMT);
      buf[i] = TRAIN;
      write(1, buf, WAY_SIZE);
      i++;
      sleep(1);
    }
  return (NULL);
}

static void	*on_bridge(void *tp)
{
  pthread_mutex_lock(PTHREAD_MUTEX(&TP(tp)->mutex_bridge));
  pthread_cond_wait(PTHREAD_COND(&TP(tp)->cond_bridge),
		    PTHREAD_MUTEX(&TP(tp)->mutex_bridge));
  pthread_cond_signal(PTHREAD_COND(&TP(tp)->cond_train));
  pthread_mutex_unlock(PTHREAD_MUTEX(&TP(tp)->mutex_bridge));
  return (NULL);
}

int	main(void)
{
  t_tp	tp;
  int	i;

  pthread_cond_init(PTHREAD_COND(&tp.cond_train), NULL);
  pthread_cond_init(PTHREAD_COND(&tp.cond_bridge), NULL);
  pthread_mutex_init(PTHREAD_MUTEX(&tp.mutex_bridge), NULL);
  pthread_create(PTHREAD(&tp.bridge), NULL, on_bridge, &tp);
  for (i = 0; i < NB_TRAINS; i++)
    pthread_create(PTHREAD(&tp.train[i]), NULL, on_way, &tp);
  for (i = 0; i < NB_TRAINS; i++)
    pthread_join(PTHREAD_VALUE(tp.train[i]), NULL);
  pthread_join(PTHREAD_VALUE(tp.bridge), NULL);
  pthread_mutex_destroy(PTHREAD_MUTEX(&tp.mutex_bridge));
  return (0);
}

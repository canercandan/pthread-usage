/*
** main.c for tp in /home/candan_c/cu/rendu/project/philo1/tp
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Fri May  2 23:26:43 2008 caner candan
** Last update Tue May  6 07:37:32 2008 caner candan
*/

#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

# define NB_CLIENTS	3
# define WAY		"=====|----|====="
# define SIZE_WAY	16
# define CRITIC_MIN	5
# define CRITIC_MAX	10

typedef struct		s_thr
{
  pthread_t		train[NB_CLIENTS];
  pthread_t		bridge;
  pthread_mutex_t	mutex_bridge;
  pthread_cond_t	cond_bridge;
  pthread_cond_t	cond_train;
}			t_thr;

static void	*through_bridge(void *data)
{
  t_thr		*thr;

  thr = data;
  while (42)
    {
      pthread_mutex_trylock(&thr->mutex_bridge);
      pthread_cond_wait(&thr->cond_bridge, &thr->mutex_bridge);
      pthread_cond_signal(&thr->cond_train);
      pthread_mutex_unlock(&thr->mutex_bridge);
    }
  return (NULL);
}

static void	*run_train(void *data)
{
  t_thr		*thr;
  char		buf[SIZE_WAY];
  int		i;

  thr = data;
  i = 0;
  while (42)
    {
      strncpy(buf, WAY, SIZE_WAY);
      buf[i] = '#';
      write(1, buf, SIZE_WAY);
      write(1, "\n", 2);
      if (i == CRITIC_MIN)
	{
	  pthread_mutex_trylock(&thr->mutex_bridge);
	  pthread_cond_signal(&thr->cond_bridge);
	  pthread_cond_wait(&thr->cond_train, &thr->mutex_bridge);
	}
      if (i == CRITIC_MAX)
	{
	  pthread_cond_signal(&thr->cond_train);
	  pthread_mutex_unlock(&thr->mutex_bridge);
	}
      if (i == SIZE_WAY - 1)
	i = 0;
      else
	i++;
      sleep(1);
    }
  return (NULL);
}

int	main(void)
{
  t_thr	thr;
  int	i;

  pthread_cond_init(&thr.cond_train, NULL);
  pthread_cond_init(&thr.cond_bridge, NULL);
  pthread_mutex_init(&thr.mutex_bridge, NULL);
  if (!pthread_create(&thr.bridge, NULL, through_bridge, &thr))
    for (i = 0; i < NB_CLIENTS; i++)
      pthread_create(&thr.train[i], NULL, run_train, &thr);
  for (i = 0; i < NB_CLIENTS; i++)
    pthread_join(thr.train[i], NULL);
  pthread_join(thr.bridge, NULL);
  pthread_mutex_destroy(&thr.mutex_bridge);
  return (0);
}

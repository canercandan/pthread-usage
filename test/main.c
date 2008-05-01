/*
** mutex.c for mutex in /home/candan_c/cu/rendu/project/philo1/test
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu May  1 09:21:52 2008 caner candan
** Last update Thu May  1 13:24:50 2008 caner candan
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include "philo1.h"
#include "x.h"

static int	get_random(int max)
{
  double	val;

  val = (double) max * rand();
  val = val / (RAND_MAX + 1.0);
  return ((int) val);
}

static void	*do_store(void *mem)
{
  t_mem		*m;

  debug("do_store()", 1);
  m = mem;
  while (1)
    {
      pthread_mutex_trylock((pthread_mutex_t *) &m->mutex);
      if (m->qte <= 0)
	{
	  m->qte = 20;
	  printf("Stock the store.\n");
	}
      pthread_mutex_unlock((pthread_mutex_t *) &m->mutex);
    }
  return (NULL);
}

static void	*do_clients(void *mem)
{
  t_mem		*m;
  int		val;

  debug("do_clients()", 1);
  m = mem;
  while (1)
    {
      pthread_mutex_trylock((pthread_mutex_t *) &m->mutex);
      val = get_random(6);
      sleep(get_random(3));
      m->qte -= val;
      printf("One client take %d, stock = %d.\n", val, m->qte);
      pthread_mutex_unlock((pthread_mutex_t *) &m->mutex);
    }
  return (NULL);
}

int	main(void)
{
  t_mem	mem;
  int	rc;
  int	i;

  debug("main()", 0);
  mem.mutex = PTHREAD_MUTEX_INITIALIZER;
  if (!(rc = pthread_create((pthread_t *) &mem.stock, NULL, do_store, &mem)))
    {
      printf("Store has been created.\n");
      for (i = 0; i < NB_CLIENTS; i++)
	{
	  pthread_create((pthread_t *) &mem.client[i], NULL,
			 do_clients, &mem);
	  printf("Client %d has been created.\n", i);
	}
    }
  for (i = 0; i < NB_CLIENTS; i++)
    pthread_join(mem.client[i], NULL);
  pthread_join(mem.stock, NULL);
  return (0);
}

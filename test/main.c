/*
** mutex.c for mutex in /home/candan_c/cu/rendu/project/philo1/test
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu May  1 09:21:52 2008 caner candan
** Last update Fri May  2 13:29:57 2008 caner candan
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
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
  m->qte = 0;
  while (1)
    {
      xpthread_mutex_trylock(&m->mutex_stock);
      xpthread_cond_wait(&m->cond_stock, &m->mutex_stock);
      m->qte = 20;
      printf("Stock the store.\n");
      xpthread_cond_signal(&m->cond_clients);
      xpthread_mutex_unlock(&m->mutex_stock);
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
      val = get_random(6);
      sleep(get_random(3));
      xpthread_mutex_trylock(&m->mutex_stock);
      if (val > m->qte)
	{
	  xpthread_cond_signal(&m->cond_stock);
	  xpthread_cond_wait(&m->cond_clients, &m->mutex_stock);
	}
      m->qte -= val;
      printf("One client take %d, stock = %d.\n", val, m->qte);
      xpthread_mutex_unlock(&m->mutex_stock);
    }
  return (NULL);
}

int	main(void)
{
  t_mem	mem;
  int	rc;
  int	i;

  debug("main()", 0);
  xpthread_cond_init(&mem.cond_clients, NULL);
  xpthread_cond_init(&mem.cond_stock, NULL);
  xpthread_mutex_init(&mem.mutex_stock, NULL);
  if (!(rc = xpthread_create(&mem.stock, NULL, do_store, &mem)))
    {
      printf("Store has been created.\n");
      for (i = 0; i < NB_CLIENTS; i++)
	{
	  xpthread_create(&mem.client[i], NULL,
			 do_clients, &mem);
	  printf("Client %d has been created.\n", i);
	}
    }
  for (i = 0; i < NB_CLIENTS; i++)
    xpthread_join(mem.client[i], NULL);
  xpthread_join(mem.stock, NULL);
  xpthread_mutex_destroy(&mem.mutex_stock);
  xpthread_cond_destroy(&mem.cond_stock);
  xpthread_cond_destroy(&mem.cond_clients);
  return (0);
}

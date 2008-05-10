/*
** create_thread.c for philo1 in /u/epitech_2010s/hochwe_f/cu/rendu/c/philo1
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Sat May 10 12:28:46 2008 florent hochwelker
** Last update Sat May 10 12:50:25 2008 florent hochwelker
*/

#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include "philo1.h"

static pthread_mutex_t	stick[NB];

static int		get_id(int thread_id, int direction)
{
  thread_id += direction;
  if (thread_id == NB)
    thread_id = 0;
  if (thread_id == -1)
    thread_id = NB - 1;
  return (thread_id);
}

static void		*start_routine(void *thread_id)
{
  long			id;
  int			status;
  int			hp;

  id = (long)thread_id;
  status = 0;
  hp = 3;
  while (1)
    {
      if (status == THINK)
	{
	  if (pthread_mutex_trylock(stick + get_id(id, LEFT)) == 0)
	    status++;
	}
      else if (status == EAT)
	{
	  hp += 2;
	  pthread_mutex_unlock(stick + get_id(id, RIGHT));
	  pthread_mutex_unlock(stick + get_id(id, LEFT));
	  status = 0;
	}
      else
	{
	  hp--;
	  if (pthread_mutex_trylock(stick + get_id(id, RIGHT)) == 0)
	    {
	      status++;
	      if (pthread_mutex_trylock(stick + get_id(id, LEFT)) == 0)
		status++;
	    }
	}
      if (id == 0)
	my_putstr("----\n");
      my_putchar(id + '0');
      my_putstr(": mon etat est ");
      my_putchar(status + '0');
      my_putstr(" j'ai ");
      my_putnbr(hp);
      my_putstr(" hp\n");
      sleep(1);
    }
  pthread_exit(NULL);
}

int		create_thread()
{
  pthread_t	*threads;
  int		r;
  long		i;

  threads = malloc(sizeof(*threads) * NB);
  i = 0;
  while (i < NB)
    {
      pthread_mutex_init(&stick[i], 0);
      i++;
    }
  i = 0;
  while (i < NB)
    {
      if ((r = pthread_create(&threads[i], NULL, start_routine, (void *)i)))
	{
	  my_putstr("Thread error\n");
	  exit(-1);
	}
      i++;
    }
  pthread_exit(NULL);
}

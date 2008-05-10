/*
** create_thread.c for philo1 in /u/epitech_2010s/hochwe_f/cu/rendu/c/philo1
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Sat May 10 12:28:46 2008 florent hochwelker
** Last update Sat May 10 17:42:01 2008 florent hochwelker
*/

#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include "philo1.h"

static pthread_mutex_t	stick[NB];
int			status[NB];
int			hp[NB];

static void		change_status(int id)
{
  if (status[id] == EAT)
    {
      hp[id] += 1;
      pthread_mutex_unlock(stick + get_id(id, RIGHT));
      pthread_mutex_unlock(stick + get_id(id, LEFT));
      status[id] = 0;
    }
  else
    {
      if (pthread_mutex_lock(stick + get_id(id, RIGHT)) == 0)
	{
	  status[id]++;
	  if (pthread_mutex_lock(stick + get_id(id, LEFT)) == 0)
	    status[id]++;
	}
    }
}

static void		*start_routine(void *info)
{
  int			id;
  int			sdl_on;

  id = (long)info & 0xff;
  sdl_on = (long)info & 0xff00;
  hp[id] = 0;
  status[id] = 0;
  while (1)
    {
      change_status(id);
      sleep(1);
    }
  pthread_exit(NULL);
}

int		create_thread(int sdl_on)
{
  pthread_t	*threads;
  int		r;
  int		i;
  long		info;

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
      info = 0;
      info |= i;
      info |= (sdl_on << 8);
      if ((r = pthread_create(&threads[i], NULL, start_routine, (void *)info)))
	{
	  my_putstr("Thread error\n");
	  exit(-1);
	}
      i++;
    }
  while (1)
    {
      i = 0;
      while (i < NB)
	print_status(i++);
      sleep(1);
    }
  pthread_exit(NULL);
}

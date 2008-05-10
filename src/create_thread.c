/*
** create_thread.c for philo1 in /u/epitech_2010s/hochwe_f/cu/rendu/c/philo1
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Sat May 10 12:28:46 2008 florent hochwelker
** Last update Sat May 10 15:31:04 2008 florent hochwelker
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

static void		print_status(int id, int status, int hp)
{
  if (id == 0)
    my_putstr("----\n");
  my_putchar(id + '0');
  my_putstr(": mon etat est ");
  if (status == THINK)
    my_putstr("\"reflechi\"");
  else if (status == EAT)
    my_putstr("\"mange\"");
  else
    my_putstr("\"dort\"");
  my_putstr(", j'ai ");
  my_putnbr(hp);
  my_putstr(" hp\n");
}

static void		change_status(int *status, int id, int *hp)
{
  if (*status == THINK)
    {
      if (pthread_mutex_trylock(stick + get_id(id, LEFT)) == 0)
	(*status)++;
    }
  else if (*status == EAT)
    {
      *hp += 1;
      pthread_mutex_unlock(stick + get_id(id, RIGHT));
      pthread_mutex_unlock(stick + get_id(id, LEFT));
      *status = 0;
    }
  else
    {
      if (pthread_mutex_trylock(stick + get_id(id, RIGHT)) == 0)
	{
	  (*status)++;
	  if (pthread_mutex_trylock(stick + get_id(id, LEFT)) == 0)
	    (*status)++;
	}
    }
}

static void		*start_routine(void *info)
{
  int			id;
  int			sdl_on;
  int			status;
  int			hp;

  id = (long)info & 0xff;
  sdl_on = (long)info & 0xff00;
  status = 0;
  hp = 1;
  while (1)
    {
      change_status(&status, id, &hp);
      if (!sdl_on)
	print_status(id, status, hp);
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
  pthread_exit(NULL);
}

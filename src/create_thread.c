/*
** create_thread.c for philo1 in /u/epitech_2010s/hochwe_f/cu/rendu/c/philo1
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Sat May 10 12:28:46 2008 florent hochwelker
** Last update Sat May 10 21:19:15 2008 florent hochwelker
*/

#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include "philo1.h"
#include "x.h"

int			*gl_status;
int			*gl_hp;
static pthread_mutex_t	*stick;

static void		change_status(int id, int nb_philo)
{
  if (gl_status[id] == EAT)
    {
      gl_hp[id] += 1;
      xpthread_mutex_unlock(stick + get_id(id, RIGHT, nb_philo));
      xpthread_mutex_unlock(stick + get_id(id, LEFT, nb_philo));
      gl_status[id] = 0;
    }
  else
    {
      if (pthread_mutex_lock(stick + get_id(id, RIGHT, nb_philo)) == 0)
	{
	  gl_status[id]++;
	  if (pthread_mutex_lock(stick + get_id(id, LEFT, nb_philo)) == 0)
	    gl_status[id]++;
	}
    }
}

static void	*start_routine(void *info)
{
  int		id;
  int		nb_philo;

  id = (long)info & 0xff;
  nb_philo = ((long)info >> 8) & 0xff;
  gl_hp[id] = 0;
  gl_status[id] = 0;
  while (1)
    {
      change_status(id, nb_philo);
      sleep(1);
    }
  pthread_exit(NULL);
}

static int	loop_print(int nb_philo)
{
  int		i;

  i = 0;
  while (1)
    {
      i = 0;
      while (i < nb_philo)
	print_status(i++);
      sleep(1);
    }
  pthread_exit(NULL);
}

int		create_thread(int sdl_on, int nb_philo)
{
  pthread_t	*threads;
  int		info;
  int		i;

  threads = xmalloc(sizeof(*threads) * nb_philo);
  gl_status = xmalloc(sizeof(*gl_status) * nb_philo);
  gl_hp = xmalloc(sizeof(*gl_hp) * nb_philo);
  stick = xmalloc(sizeof(*stick) * nb_philo);
  i = 0;
  while (i < nb_philo)
    xpthread_mutex_init(&stick[i++], 0);
  i = 0;
  while (i < nb_philo)
    {
      info = 0;
      info |= i;
      info |= nb_philo << 8;
      xpthread_create(&threads[i], NULL, start_routine, (void *)info);
      i++;
    }
  if (!sdl_on)
    loop_print(nb_philo);
  pthread_exit(NULL);
}

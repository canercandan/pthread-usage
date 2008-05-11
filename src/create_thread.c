/*
** create_thread.c for philo1 in /u/epitech_2010s/hochwe_f/cu/rendu/c/philo1
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Sat May 10 12:28:46 2008 florent hochwelker
** Last update Sun May 11 11:57:03 2008 caner candan
*/

#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include "philo1.h"
#include "x.h"

t_info	gl_info;

static void		change_status(int id)
{
  if (gl_info.status[id] == EAT)
    {
      gl_info.hp[id] += 1;
      xpthread_mutex_unlock(PTHREAD_MUTEX(gl_info.stick)
			    + get_id(id, RIGHT, gl_info.nb_sticks));
      xpthread_mutex_unlock(PTHREAD_MUTEX(gl_info.stick)
			    + get_id(id, LEFT, gl_info.nb_sticks));
      gl_info.status[id] = 0;
    }
  else
    if (!pthread_mutex_lock(PTHREAD_MUTEX(gl_info.stick)
			    + get_id(id, RIGHT, gl_info.nb_sticks)))
      {
	gl_info.status[id]++;
	if (!pthread_mutex_lock(PTHREAD_MUTEX(gl_info.stick)
				+ get_id(id, LEFT, gl_info.nb_sticks)))
	  gl_info.status[id]++;
      }
}

static void	*start_routine(void *data)
{
  int		id;

  id = (int)data;
  gl_info.hp[id] = 0;
  gl_info.status[id] = 0;
  while (1)
    {
      change_status(id);
      sleep(1);
    }
  pthread_exit(NULL);
}

static int	loop_print(void)
{
  int		i;

  i = 0;
  while (1)
    {
      i = 0;
      while (i < gl_info.nb_philos)
	print_status(i++);
      sleep(1);
    }
  pthread_exit(NULL);
}

int		create_thread(int sdl_on)
{
  int		i;

  gl_info.threads = xmalloc(sizeof(*PTHREAD(gl_info.threads))
			    * gl_info.nb_philos);
  gl_info.status = xmalloc(sizeof(*gl_info.status) * gl_info.nb_philos);
  gl_info.hp = xmalloc(sizeof(*gl_info.hp) * gl_info.nb_philos);
  gl_info.stick = xmalloc(sizeof(*PTHREAD_MUTEX(gl_info.stick))
			  * gl_info.nb_sticks);
  i = 0;
  while (i < gl_info.nb_philos)
    xpthread_mutex_init(&PTHREAD_MUTEX(gl_info.stick)[i++], 0);
  i = 0;
  while (i < gl_info.nb_philos)
    {
      xpthread_create(&(PTHREAD(gl_info.threads)[i]), NULL, start_routine,
		      (void *)i);
      i++;
    }
  if (!sdl_on)
    loop_print();
  pthread_exit(NULL);
}

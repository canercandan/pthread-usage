/*
** create_thread.c for philo1 in /u/epitech_2010s/hochwe_f/cu/rendu/c/philo1
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Sat May 10 12:28:46 2008 florent hochwelker
** Last update Sun May 11 15:16:19 2008 florent hochwelker
*/

#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include "philo1.h"
#include "x.h"
#include "my.h"

t_info		gl_info;

static void	change_status(int id, int *right, int *left)
{
  if (gl_info.status[id] == EAT)
    {
      gl_info.hp[id] += 1;
      xpthread_mutex_unlock(PTHREAD_MUTEX(gl_info.stick)
			    + get_id(id, RIGHT, gl_info.nb_sticks));
      xpthread_mutex_unlock(PTHREAD_MUTEX(gl_info.stick)
			    + get_id(id, LEFT, gl_info.nb_sticks));
      *right = 0;
      *left = 0;
      gl_info.status[id] = SLEEP;
    }
  else
    if (!pthread_mutex_lock(PTHREAD_MUTEX(gl_info.stick)
			    + get_id(id, RIGHT, gl_info.nb_sticks)))
      {
	gl_info.status[id]++;
	*right = 1;
	if (!pthread_mutex_lock(PTHREAD_MUTEX(gl_info.stick)
				+ get_id(id, LEFT, gl_info.nb_sticks)))
	  {
	    gl_info.status[id]++;
	    *left = 1;
	  }
      }
}

static void	*start_routine(void *data)
{
  int		id;
  int		right;
  int		left;

  id = (long)data;
  right = 0;
  left = 0;
  gl_info.hp[id] = 0;
  gl_info.status[id] = 0;
  while (1)
    {
      if (gl_info.end)
	{
	  destroy_mutex(id, right, left);
	  pthread_exit(NULL);
	}
      change_status(id, &right, &left);
      if (!gl_info.end)
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
      while (i < gl_info.nb_philos && !gl_info.end)
	print_status(i++);
      if (gl_info.end)
	break;
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
		      (void *)((long)i));
      i++;
    }
  if (!sdl_on)
    loop_print();
  pthread_exit(NULL);
}

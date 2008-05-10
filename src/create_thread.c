/*
** create_thread.c for philo1 in /u/epitech_2010s/hochwe_f/cu/rendu/c/philo1
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Sat May 10 12:28:46 2008 florent hochwelker
** Last update Sat May 10 22:44:43 2008 caner candan
*/

#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include "philo1.h"
#include "x.h"

int			*gl_status;
int			*gl_hp;
void			*gl_stick;

static void		change_status(int id, int nb_sticks)
{
  if (gl_status[id] == EAT)
    {
      gl_hp[id] += 1;
      xpthread_mutex_unlock(PTHREAD_MUTEX(gl_stick)
			    + get_id(id, RIGHT, nb_sticks));
      xpthread_mutex_unlock(PTHREAD_MUTEX(gl_stick)
			    + get_id(id, LEFT, nb_sticks));
      gl_status[id] = 0;
    }
  else
    if (!pthread_mutex_lock(PTHREAD_MUTEX(gl_stick)
			    + get_id(id, RIGHT, nb_sticks)))
      {
	gl_status[id]++;
	if (!pthread_mutex_lock(PTHREAD_MUTEX(gl_stick)
				+ get_id(id, LEFT, nb_sticks)))
	  gl_status[id]++;
      }
}

static void	*start_routine(void *data)
{
  int		id;
  int		nb_sticks;

  id = (long)data & 0xff;
  nb_sticks = ((long)data >> 8) & 0xff;
  gl_hp[id] = 0;
  gl_status[id] = 0;
  while (1)
    {
      change_status(id, nb_sticks);
      sleep(1);
    }
  pthread_exit(NULL);
}

static int	loop_print(int nb_philos)
{
  int		i;

  i = 0;
  while (1)
    {
      i = 0;
      while (i < nb_philos)
	print_status(i++);
      sleep(1);
    }
  pthread_exit(NULL);
}

int		create_thread(int sdl_on, t_info *info)
{
  int		data;
  int		i;

  info->threads = xmalloc(sizeof(*PTHREAD(info->threads)) * info->nb_philos);
  gl_status = xmalloc(sizeof(*gl_status) * info->nb_philos);
  gl_hp = xmalloc(sizeof(*gl_hp) * info->nb_philos);
  gl_stick = xmalloc(sizeof(*PTHREAD_MUTEX(gl_stick)) * info->nb_sticks);
  i = 0;
  while (i < info->nb_philos)
    xpthread_mutex_init(&PTHREAD_MUTEX(gl_stick)[i++], 0);
  i = 0;
  while (i < info->nb_philos)
    {
      data = 0;
      data |= i;
      data |= info->nb_sticks << 8;
      xpthread_create(&(PTHREAD(info->threads)[i]), NULL, start_routine, (void *)data);
      i++;
    }
  if (!sdl_on)
    loop_print(info->nb_philos);
  pthread_exit(NULL);
}

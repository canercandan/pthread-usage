/*
** destroy_mutex.c for philo1 in /home/hochwe_f/afs/rendu/c/philo1
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Sun May 11 12:32:21 2008 florent hochwelker
** Last update Sun May 11 18:39:26 2008 caner candan
*/

#include <pthread.h>
#include "philo1.h"
#include "x.h"

t_info	gl_info;

void	destroy_mutex(int id, int right, int left)
{
  if (right)
    {
      xpthread_mutex_unlock(PTHREAD_MUTEX(gl_info.stick)
			    + get_id(id, RIGHT, gl_info.nb_sticks));
    }
  if (left)
    {
      xpthread_mutex_unlock(PTHREAD_MUTEX(gl_info.stick)
			    + get_id(id, LEFT, gl_info.nb_sticks));
    }
  gl_info.end++;
}

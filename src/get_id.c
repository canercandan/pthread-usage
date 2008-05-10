/*
** get_id.c for philo1 in /home/hochwe_f/afs/rendu/c/philo1
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Sat May 10 17:42:19 2008 florent hochwelker
** Last update Sat May 10 20:57:57 2008 florent hochwelker
*/

#include "philo1.h"

int	get_id(int thread_id, int direction, int nb_philo)
{
  thread_id += direction;
  if (thread_id == nb_philo)
    thread_id = 0;
  if (thread_id == -1)
    thread_id = nb_philo - 1;
  return (thread_id);
}

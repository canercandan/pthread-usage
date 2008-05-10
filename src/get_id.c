/*
** get_id.c for philo1 in /home/hochwe_f/afs/rendu/c/philo1
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Sat May 10 17:42:19 2008 florent hochwelker
** Last update Sat May 10 17:48:53 2008 florent hochwelker
*/

#include "philo1.h"

int	get_id(int thread_id, int direction)
{
  thread_id += direction;
  if (thread_id == NB)
    thread_id = 0;
  if (thread_id == -1)
    thread_id = NB - 1;
  return (thread_id);
}

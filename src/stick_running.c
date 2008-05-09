/*
** stick_running.c for philo1 in /home/candan_c/cu/rendu/project/philo1
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Fri May  9 16:30:04 2008 caner candan
** Last update Fri May  9 16:32:07 2008 caner candan
*/

#include <unistd.h>
#include "philo1.h"

void	*stick_running(void *info)
{
  (void) info;
  while (42)
    {
      write(1, "STICK\n", 6);
      sleep(1);
    }
  return (NULL);
}

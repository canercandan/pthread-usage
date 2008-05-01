/*
** debug.c for philo1 in /home/candan_c/cu/rendu/project/philo1/test
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu May  1 11:01:41 2008 caner candan
** Last update Thu May  1 11:33:15 2008 caner candan
*/

#include <unistd.h>
#include <string.h>
#include "philo1.h"

void		debug(char *s, int pos)
{
  int		i;

  write(1, "## DEBUG ##\t", 13);
  for (i = 0; i < pos; i++)
    {
      if (i == pos - 1)
	write(1, "+", 1);
      write(1, "\t", 2);
    }
  write(1, "-> ", 3);
  write(1, s, strlen(s));
  write(1, "\n", 2);
}

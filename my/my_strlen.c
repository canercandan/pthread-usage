/*
** my_strlen.c for philo1 in /u/epitech_2010s/hochwe_f/cu/rendu/c/philo1
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Sat May 10 12:15:08 2008 florent hochwelker
** Last update Sat May 10 22:39:33 2008 caner candan
*/

#include "my.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (*str++)
    i++;
  return (i);
}

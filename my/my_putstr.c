/*
** my_putstr.c for philo1 in /u/epitech_2010s/hochwe_f/cu/rendu/c/philo1
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Sat May 10 12:46:57 2008 florent hochwelker
** Last update Sat May 10 22:38:57 2008 caner candan
*/

#include <unistd.h>
#include "my.h"

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

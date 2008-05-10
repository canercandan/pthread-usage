/*
** my_putstr.c for philo1 in /u/epitech_2010s/hochwe_f/cu/rendu/c/philo1
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Sat May 10 12:46:57 2008 florent hochwelker
** Last update Sat May 10 12:53:09 2008 florent hochwelker
*/

#include <unistd.h>
#include "philo1.h"

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

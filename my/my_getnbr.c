/*
** my_getnbr.c for philo1 in /home/hochwe_f/afs/rendu/c/philo1
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Sat May 10 20:21:56 2008 florent hochwelker
** Last update Sat May 10 22:39:11 2008 caner candan
*/

#include "my.h"

int	my_getnbr(char *str)
{
  int	i;
  int	signe;
  int	result;
  int	debut_nombre;

  signe = 1;
  result = 0;
  i = 0;
  debut_nombre = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '-' && debut_nombre == 0)
	signe *= -1;
      else if ((str[i] >= 48) && (str[i] <= 57) && debut_nombre < 2)
	{
	  debut_nombre = 1;
	  result += str[i] - 48;
	}
      else if (debut_nombre == 1)
	debut_nombre = 2;
      i++;
    }
  return (result * signe);
}

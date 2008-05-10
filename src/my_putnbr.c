/*
** my_putnbr.c for philo1 in /home/candan_c/cu/rendu/project/philo1
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sat May 10 12:21:36 2008 caner candan
** Last update Sat May 10 12:38:30 2008 florent hochwelker
*/

#include <unistd.h>

void	my_putnbr(unsigned int n)
{
  int	rest;
  char	c;

  rest = n % 10;
  n = n / 10;
  if (n != 0)
    my_putnbr(n);
  c = rest + '0';
  write(1, &c, 1);
}

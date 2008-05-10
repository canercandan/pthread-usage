/*
** my_putchar.c for philo1 in /u/epitech_2010s/hochwe_f/cu/rendu/c/philo1
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Sat May 10 12:15:31 2008 florent hochwelker
** Last update Sat May 10 12:53:35 2008 florent hochwelker
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

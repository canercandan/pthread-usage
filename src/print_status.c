/*
** print_status.c for philo1 in /home/hochwe_f/afs/rendu/c/philo1
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Sat May 10 15:36:33 2008 florent hochwelker
** Last update Sun May 11 11:53:13 2008 caner candan
*/

#include "philo1.h"
#include "my.h"

t_info	gl_info;

void	print_status(int id)
{
  if (id == 0)
    my_putstr("----\n");
  my_putnbr(id);
  my_putstr(": mon etat est ");
  if (gl_info.status[id] == THINK)
    my_putstr("\"reflechi\"");
  else if (gl_info.status[id] == EAT)
    my_putstr("\"mange\"\t");
  else
    my_putstr("\"dort\"\t");
  my_putstr("\tj'ai ");
  my_putnbr(gl_info.hp[id]);
  my_putstr(" hp\n");
}

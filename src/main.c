/*
** main.c for philo1 in /home/candan_c/cu/rendu/project/philo1
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Fri May  9 19:50:37 2008 caner candan
** Last update Sat May 10 20:50:03 2008 florent hochwelker
*/

#include <pthread.h>
#include <stdlib.h>
#include "philo1.h"

int	main(int ac, char **av)
{
  if (ac == 2 && !my_strcmp(av[1], "-g"))
    {
      if (init_sdl() < 0)
	return (-1);
      return (0);
    }
  else if (ac == 3 && !my_strcmp(av[1], "-n"))
    create_thread(0, atoi(av[2]));
  else
    create_thread(0, NB);
  pthread_exit(NULL);
}

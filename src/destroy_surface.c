/*
** destroy_surface.c for philo1 in /home/candan_c/cu/rendu/project/philo1
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sat May 10 12:24:10 2008 caner candan
** Last update Sat May 10 16:10:15 2008 caner candan
*/

#include <SDL.h>
#include "philo1.h"

void	destroy_surface(void *surface)
{
  SDL_FreeSurface(surface);
}

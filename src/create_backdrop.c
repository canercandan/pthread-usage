/*
** create_backdrop.c for philo1 in /home/candan_c/cu/rendu/project/philo1
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sat May 10 15:27:22 2008 caner candan
** Last update Sun May 11 18:36:56 2008 caner candan
*/

#include <SDL.h>
#include "philo1.h"
#include "my.h"

int	create_backdrop(t_gfx *gfx)
{
  if (!(gfx->backdrop = (void *) SDL_LoadBMP(BACKDROP_FILE)))
    {
      my_putstr("SDL_LoadBMP");
      return (-1);
    }
  return (0);
}


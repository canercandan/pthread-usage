/*
** create_status.c for philo1 in /home/candan_c/cu/rendu/project/philo1
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sat May 10 17:52:53 2008 caner candan
** Last update Sun May 11 18:37:40 2008 caner candan
*/

#include <SDL.h>
#include "philo1.h"
#include "my.h"

int	create_status(t_gfx *gfx)
{
  if (!(gfx->status = (void *) SDL_LoadBMP(STATUS_FILE)))
    {
      my_putstr("SDL_LoadBMP");
      return (-1);
    }
  return (0);
}

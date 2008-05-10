/*
** create_status.c for philo1 in /home/candan_c/cu/rendu/project/philo1
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sat May 10 17:52:53 2008 caner candan
** Last update Sat May 10 18:01:02 2008 caner candan
*/

#include <SDL.h>
#include "philo1.h"

int	create_status(t_gfx *gfx)
{
  if (!(gfx->status = (void *) SDL_LoadBMP(STATUS_FILE)))
    {
      perror("SDL_LoadBMP");
      return (-1);
    }
  return (0);
}

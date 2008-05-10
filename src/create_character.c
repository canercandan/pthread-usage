/*
** create_character.c for philo1 in /home/candan_c/cu/rendu/project/philo1
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sat May 10 12:22:50 2008 caner candan
** Last update Sat May 10 15:26:41 2008 caner candan
*/

#include <SDL.h>
#include "philo1.h"

int	create_character(t_gfx *gfx)
{
  if (!(gfx->character = (void *) SDL_LoadBMP(CHARACTER_FILE)))
    {
      perror("SDL_LoadBMP");
      return (-1);
    }
  return (0);
}

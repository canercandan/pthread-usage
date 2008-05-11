/*
** create_character.c for philo1 in /home/candan_c/cu/rendu/project/philo1
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sat May 10 12:22:50 2008 caner candan
** Last update Sun May 11 18:37:06 2008 caner candan
*/

#include <SDL.h>
#include "philo1.h"
#include "my.h"

int	create_character(t_gfx *gfx)
{
  if (!(gfx->character = (void *) SDL_LoadBMP(CHARACTER_FILE)))
    {
      my_putstr("SDL_LoadBMP");
      return (-1);
    }
  return (0);
}

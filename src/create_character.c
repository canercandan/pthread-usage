/*
** create_character.c for philo1 in /home/candan_c/cu/rendu/project/philo1
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sat May 10 12:22:50 2008 caner candan
** Last update Sat May 10 13:00:34 2008 caner candan
*/

#include <SDL.h>
#include "philo1.h"

void	create_character(t_gfx *gfx)
{
  gfx->image = (void *) SDL_LoadBMP(CHARACTER_FILE);
}

/*
** destroy_screen.c for philo1 in /home/candan_c/cu/rendu/test/sdl
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sat May 10 11:23:32 2008 caner candan
** Last update Sat May 10 11:24:44 2008 caner candan
*/

#include <SDL.h>
#include "philo1.h"

void	destroy_screen(t_gfx *gfx)
{
  (void) gfx;
  SDL_Quit();
}

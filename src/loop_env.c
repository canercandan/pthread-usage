/*
** loop_env.c for philo1 in /home/candan_c/cu/rendu/project/philo1
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sat May 10 11:38:45 2008 caner candan
** Last update Sat May 10 17:24:14 2008 caner candan
*/

#include <SDL.h>
#include "philo1.h"

static void	set_character_center(t_gfx *gfx, int x, int y)
{
  set_character(gfx, 0,
		(SDL_SF(gfx->backdrop)->w / 2) - (UNIT_X * x),
		(SDL_SF(gfx->backdrop)->h / 2) - (UNIT_Y * y));
}

int		loop_env(t_gfx *gfx)
{
  if (catch_keys() < 0)
    return (-1);
  set_backdrop(gfx, 0, 0);
  set_character_center(gfx, 10, 10);
  SDL_Flip(gfx->video);
  SDL_Delay(DELAY);
  return (0);
}

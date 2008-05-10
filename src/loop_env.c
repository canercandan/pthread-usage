/*
** loop_env.c for philo1 in /home/candan_c/cu/rendu/project/philo1
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sat May 10 11:38:45 2008 caner candan
** Last update Sat May 10 18:40:45 2008 caner candan
*/

#include <SDL.h>
#include "philo1.h"

static void	set_character_center(t_gfx *gfx, int nbr, int x, int y)
{
  int		x_pos;
  int		y_pos;

  x_pos = (SDL_SF(gfx->backdrop)->w / 2) - (UNIT_X * x) - (CHARACTER_X / 2);
  y_pos = (SDL_SF(gfx->backdrop)->h / 2) - (UNIT_Y * y) - (CHARACTER_Y / 2);
  set_character(gfx, nbr, x_pos, y_pos);
  set_status(gfx, 6, x_pos - 10, y_pos - 10);
}

int		loop_env(t_gfx *gfx)
{
  if (catch_keys() < 0)
    return (-1);
  set_backdrop(gfx, 0, 0);
  set_character_center(gfx, 0, 0, 17);
  set_character_center(gfx, 0, 13, 13);
  set_character_center(gfx, 0, -13, 13);
  set_character_center(gfx, 8, 17, 0);
  set_character_center(gfx, 3, -17, 0);
  set_character_center(gfx, 9, -13, -13);
  set_character_center(gfx, 9, 13, -13);
  SDL_Flip(gfx->video);
  SDL_Delay(DELAY);
  return (0);
}

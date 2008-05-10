/*
** loop_env.c for philo1 in /home/candan_c/cu/rendu/project/philo1
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sat May 10 11:38:45 2008 caner candan
** Last update Sat May 10 15:22:45 2008 caner candan
*/

#include <SDL.h>
#include "philo1.h"

int	loop_env(t_gfx *gfx)
{
  static int	i = 0;
  int	stat[NB];

  (void) stat;
  if (catch_keys() < 0)
    return (-1);
  set_character(gfx, i % 9, 1, 1);
  set_character(gfx, i % 9, 1, 2);
  set_character(gfx, i % 9, 1, 3);
  set_character(gfx, i % 9, 3, 1);
  set_character(gfx, i % 9, 3, 2);
  set_character(gfx, i % 9, 3, 3);
  SDL_Flip(gfx->screen);
  SDL_Delay(DELAY);
  i++;
  return (0);
}

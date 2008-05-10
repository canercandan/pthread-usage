/*
** loop_env.c for philo1 in /home/candan_c/cu/rendu/project/philo1
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sat May 10 11:38:45 2008 caner candan
** Last update Sat May 10 16:22:38 2008 caner candan
*/

#include <SDL.h>
#include "philo1.h"

int		loop_env(t_gfx *gfx)
{
  static int	i = 6;
  static int	j = 0;
  static int	k = 0;
  int	stat[NB];

  if (catch_keys() < 0)
    return (-1);
  set_backdrop(gfx, 0, 0);
  set_character(gfx, i, j % 50, 35);
  SDL_Flip(gfx->video);
  SDL_Delay(DELAY);
  j++;
  k++;
  return (0);
}

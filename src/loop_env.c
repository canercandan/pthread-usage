/*
** loop_env.c for philo1 in /home/candan_c/cu/rendu/project/philo1
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sat May 10 11:38:45 2008 caner candan
** Last update Sat May 10 12:22:37 2008 caner candan
*/

#include <SDL.h>
#include "philo1.h"

int	loop_env(t_gfx *gfx)
{
  if (catch_keys() < 0)
    return (-1);
  SDL_Flip(gfx->screen);
  SDL_Delay(DELAY);
  return (0);
}

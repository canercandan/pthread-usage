/*
** catch_keys.c for philo1 in /home/candan_c/cu/rendu/project/philo1
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sat May 10 11:45:01 2008 caner candan
** Last update Sun May 11 11:11:28 2008 florent hochwelker
*/

#include <SDL.h>
#include "philo1.h"

int		catch_keys(void)
{
  SDL_Event	event;

  SDL_PollEvent(&event);
  /*   if (event.type == SDL_KEYDOWN) */
  /*     if (event.key.keysym.sym == SDLK_ESCAPE) */
  /*       return (-1); */
  /*   if (event.type == SDL_QUIT) */
  /*     return (-1); */
  return (0);
}

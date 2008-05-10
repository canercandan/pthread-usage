/*
** init_screen.c for philo1 in /home/candan_c/cu/rendu/test/sdl
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sat May 10 11:09:34 2008 caner candan
** Last update Sat May 10 16:13:56 2008 caner candan
*/

#include <SDL.h>
#include <stdio.h>
#include "philo1.h"

int	init_screen(void)
{
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
      perror("SDL_Init");
      return (-1);
    }
  return (0);
}

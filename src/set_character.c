/*
** set_character.c for philo1 in /home/candan_c/cu/rendu/project/philo1
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sat May 10 12:25:01 2008 caner candan
** Last update Sat May 10 18:14:59 2008 caner candan
*/

#include <SDL.h>
#include "philo1.h"

void		set_character(t_gfx *gfx, int nbr, int x, int y)
{
  SDL_Rect	src;
  SDL_Rect	dst;

  src.x = CHARACTER_X * GET_POSITION_X(nbr, CHARACTER_MAX_PER_LINE);
  src.y = CHARACTER_Y * GET_POSITION_Y(nbr, CHARACTER_MAX_PER_LINE);
  src.w = CHARACTER_X;
  src.h = CHARACTER_Y;
  dst.x = x;
  dst.y = y;
  dst.w = CHARACTER_X;
  dst.h = CHARACTER_Y;
  SDL_SetColorKey(gfx->character, SDL_SRCCOLORKEY,
		  SDL_MapRGB(SDL_SF(gfx->character)->format, 255, 255, 255));
  SDL_BlitSurface(gfx->character, &src, gfx->video, &dst);
}

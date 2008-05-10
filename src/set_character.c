/*
** set_character.c for philo1 in /home/candan_c/cu/rendu/project/philo1
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sat May 10 12:25:01 2008 caner candan
** Last update Sat May 10 13:18:19 2008 caner candan
*/

#include <SDL.h>
#include "philo1.h"

void		set_character(t_gfx *gfx, int nbr, int x, int y)
{
  SDL_Rect	src;
  SDL_Rect	dst;

  src.x = CHARACTER_X * GET_CHARACTER_X(nbr);
  src.y = CHARACTER_Y * GET_CHARACTER_Y(nbr);
  src.w = CHARACTER_X;
  src.y = CHARACTER_Y;
  dst.x = x;
  dst.y = y;
  dst.w = CHARACTER_X;
  dst.h = CHARACTER_Y;
  SDL_FillRect(gfx->screen, &dst,
	       SDL_MapRGB(SDL_SF(gfx->screen)->format, 0, 0, 0));
  SDL_SetColorKey(gfx->image, SDL_SRCCOLORKEY,
		  SDL_MapRGB(SDL_SF(gfx->image)->format, 255, 255, 255));
  SDL_BlitSurface(gfx->image, &src, gfx->screen, &dst);
}

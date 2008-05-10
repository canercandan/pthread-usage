/*
** set_backdrop.c for philo1 in /home/candan_c/cu/rendu/project/philo1
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sat May 10 15:36:12 2008 caner candan
** Last update Sat May 10 16:17:29 2008 caner candan
*/

#include <SDL.h>
#include "philo1.h"

void		set_backdrop(t_gfx *gfx, int x, int y)
{
  SDL_Rect	src;
  SDL_Rect	dst;

  src.x = 0;
  src.y = 0;
  src.w = SDL_SF(gfx->backdrop)->w;
  src.h = SDL_SF(gfx->backdrop)->h;
  dst.x = UNIT_X * x;
  dst.y = UNIT_Y * y;
  dst.w = SDL_SF(gfx->backdrop)->w;
  dst.h = SDL_SF(gfx->backdrop)->h;
  SDL_SetColorKey(gfx->backdrop, SDL_SRCCOLORKEY,
		  SDL_MapRGB(SDL_SF(gfx->backdrop)->format, 255, 255, 255));
  SDL_BlitSurface(gfx->backdrop, &src, gfx->video, &dst);
}

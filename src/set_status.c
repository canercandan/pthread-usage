/*
** set_status.c for philo1 in /home/candan_c/cu/rendu/project/philo1
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sat May 10 17:59:34 2008 caner candan
** Last update Sat May 10 18:18:29 2008 caner candan
*/

#include <SDL.h>
#include "philo1.h"

void		set_status(t_gfx *gfx, int nbr, int x, int y)
{
  SDL_Rect	src;
  SDL_Rect	dst;

  src.x = STATUS_X * GET_POSITION_X(nbr, STATUS_MAX_PER_LINE);
  src.y = STATUS_Y * GET_POSITION_Y(nbr, STATUS_MAX_PER_LINE);
  src.w = STATUS_X;
  src.h = STATUS_Y;
  dst.x = x;
  dst.y = y;
  dst.w = STATUS_X;
  dst.h = STATUS_Y;
  SDL_SetColorKey(gfx->status, SDL_SRCCOLORKEY,
		  SDL_MapRGB(SDL_SF(gfx->status)->format, 192, 192, 192));
  SDL_BlitSurface(gfx->status, &src, gfx->video, &dst);
}

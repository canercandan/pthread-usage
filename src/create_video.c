/*
** create_video.c for philo1 in /home/candan_c/cu/rendu/project/philo1
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sat May 10 16:07:13 2008 caner candan
** Last update Sat May 10 16:12:07 2008 caner candan
*/

#include <SDL.h>
#include "philo1.h"

int	create_video(t_gfx *gfx)
{
  gfx->infos = (void *) SDL_GetVideoInfo();
  if (!(gfx->video = SDL_SetVideoMode(SDL_SF(gfx->backdrop)->w,
				      SDL_SF(gfx->backdrop)->h,
				      SDL_VI(gfx->infos)->vfmt->BitsPerPixel,
				      SDL_VI(gfx->infos)->video_mem)))
    {
      perror("SDL_SetVideoMode");
      return (-1);
    }
  return (0);
}

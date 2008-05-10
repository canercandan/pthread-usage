/*
** loop_env.c for philo1 in /home/candan_c/cu/rendu/project/philo1
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sat May 10 11:38:45 2008 caner candan
** Last update Sat May 10 20:39:43 2008 florent hochwelker
*/

#include <SDL.h>
#include "philo1.h"

int	*gl_status;
int	*gl_hp;

static t_pos	pos[] = {
  {0, 0, 0, 17},
  {1, 0, 13, 13},
  {2, 8, 17, 0},
  {3, 9, 13, -13},
  {4, 9, -13, -13},
  {5, 3, -17, 0},
  {6, 0, -13, 13},
  {-1, 0, 0, 0}
};

static void	get_status(t_gfx *gfx, t_pos *pos, int x, int y)
{
  if (gl_status[pos->id] == EAT)
    set_status(gfx, 6, x, y);
  else if (gl_status[pos->id] == SLEEP)
    set_status(gfx, 7, x, y);
  else
    set_status(gfx, 4, x, y);
}

static void	set_character_center(t_gfx *gfx, t_pos *pos)
{
  int		x_pos;
  int		y_pos;

  x_pos = (SDL_SF(gfx->backdrop)->w / 2) - (UNIT_X * pos->x)
    - (CHARACTER_X / 2);
  y_pos = (SDL_SF(gfx->backdrop)->h / 2) - (UNIT_Y * pos->y)
    - (CHARACTER_Y / 2);
  set_character(gfx, pos->direction, x_pos, y_pos);
  get_status(gfx, pos, x_pos - 10, y_pos - 10);
}

static void	create_pos(t_gfx *gfx)
{
  int		i;

  i = 0;
  while (pos[i].id >= 0)
    {
      set_character_center(gfx, &pos[i]);
      i++;
    }
}

int		loop_env(t_gfx *gfx)
{
  if (catch_keys() < 0)
    return (-1);
  set_backdrop(gfx, 0, 0);
  create_pos(gfx);
  SDL_Flip(gfx->video);
  SDL_Delay(DELAY);
  return (0);
}

/*
** loop_env.c for philo1 in /home/candan_c/cu/rendu/project/philo1
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sat May 10 11:38:45 2008 caner candan
** Last update Sun May 11 18:55:13 2008 caner candan
*/

#include <SDL.h>
#include "philo1.h"

t_info	gl_info;

static t_pos	pos[] = {
  {0, 0, 0, 17, 0, 0, -42, 0},
  {1, 0, 13, 13, 0, 0, -42, 0},
  {2, 8, 17, 0, 0, 0, -42, 0},
  {3, 12, 13, -13, 0, 0, -42, 0},
  {4, 12, -13, -13, 0, 0, -42, 0},
  {5, 4, -17, 0, 0, 0, -42, 0},
  {6, 0, -13, 13, 0, 0, -42, 0}
};

static void	create_pos(t_gfx *gfx)
{
  int		i;
  int		x_pos;
  int		y_pos;

  i = 0;
  while (i < NB)
    {
      if (!pos[i].visible)
	break;
      x_pos = SET_CHAR_X((SDL_SF(gfx->backdrop)->w / 2), pos[i].x);
      y_pos = SET_CHAR_Y((SDL_SF(gfx->backdrop)->h / 2), pos[i].y);
      set_character(gfx, pos[i].direction, x_pos, y_pos);
      if (pos[NB - 1].visible)
	{
	  if (gl_info.status[pos[i].id] == EAT)
	    set_status(gfx, 6, x_pos - 10, y_pos - 10);
	  else if (gl_info.status[pos[i].id] == SLEEP)
	    set_status(gfx, 7, x_pos - 10, y_pos - 10);
	  else
	    set_status(gfx, 4, x_pos - 10, y_pos - 10);
	}
      i++;
    }
}

static void	get_direction(t_pos *pos)
{
  pos->cur_direction++;
  if (pos->cur_y < pos->y)
    {
      if (pos->cur_direction < 12 || pos->cur_direction > 15)
	pos->cur_direction = 12;
    }
  else if (pos->cur_x < pos->x)
    {
      if (pos->cur_direction < 4 || pos->cur_direction > 7)
	pos->cur_direction = 4;
    }
  else if (pos->cur_x > pos->x)
    if (pos->cur_direction < 8 || pos->cur_direction > 11)
      pos->cur_direction = 8;
}

static char	init_anim(t_gfx *gfx, t_pos *pos)
{
  if (pos->cur_y != pos->y || pos->cur_x != pos->x)
    {
      if (pos->cur_y == -42)
	pos->cur_y = (((SDL_SF(gfx->backdrop)->h / 2)
		       - (CHARACTER_Y / 2)) / UNIT_Y) * -1;
      get_direction(pos);
      set_character(gfx, pos->cur_direction,
		    SET_CHAR_X((SDL_SF(gfx->backdrop)->w / 2), pos->cur_x),
		    SET_CHAR_Y((SDL_SF(gfx->backdrop)->h / 2), pos->cur_y));
      if (pos->cur_y < pos->y)
	pos->cur_y++;
      else if (pos->cur_x < pos->x)
	pos->cur_x++;
      else if (pos->cur_x > pos->x)
	pos->cur_x--;
      return (0);
    }
  pos->visible = 1;
  return (1);
}

int		loop_env(t_gfx *gfx)
{
  static int	i = 0;

  if (catch_keys() < 0)
    return (-1);
  set_backdrop(gfx, 0, 0);
  create_pos(gfx);
  if (i < NB)
    {
      if (init_anim(gfx, &pos[i]))
	i++;
      SDL_Flip(gfx->video);
      SDL_Delay(DELAY_ANIM);
    }
  else
    {
      SDL_Flip(gfx->video);
      SDL_Delay(DELAY);
    }
  return (0);
}

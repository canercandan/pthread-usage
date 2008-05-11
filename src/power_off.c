/*
** power_off.c for philo1 in /home/candan_c/cu/rendu/project/philo1
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun May 11 15:27:29 2008 caner candan
** Last update Sun May 11 17:30:41 2008 caner candan
*/

#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "philo1.h"
#include "x.h"
#include "my.h"

t_info	gl_info;

void	power_off(int signal)
{
  if (signal != 0 && gl_info.mode_gfx == 1)
    my_putstr("\nHit escape key for exit\n");
  else
    {
      (void)signal;
      my_putstr("\nDestroy thread...\n");
#ifdef __SDL__
      if (gl_info.mode_gfx == 1)
	{
	  destroy_surface(gl_info.gfx.status);
	  destroy_surface(gl_info.gfx.character);
	  destroy_surface(gl_info.gfx.backdrop);
	  destroy_surface(gl_info.gfx.video);
	  destroy_screen();
	}
#endif /* !__SDL__ */
      gl_info.end = 1;
      free(gl_info.stick);
      free(gl_info.status);
      free(gl_info.hp);
      free(gl_info.threads);
      my_putstr(PWR_OFF_MESG);
      exit(0);
    }
}

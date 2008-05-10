/*
** philo1.h for philo1 in /home/candan_c/cu/rendu/project/philo1
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue May  6 15:45:38 2008 caner candan
** Last update Sat May 10 12:53:14 2008 florent hochwelker
*/

#ifndef __PHILO1_H__
# define __PHILO1_H__

# define NB	7

# define SLEEP	0
# define THINK	1
# define EAT	2

# define RIGHT	0
# define LEFT	1

/*
** Terminal's messages
*/
# define PWR_OFF_MESG	"\nPhilosOFF\n"

/*
** SDL's defines
*/
# define SCREEN_X	640
# define SCREEN_Y	480
# define DELAY		500

/*
** Null's define
*/
# ifndef NULL
#  define NULL		((void *)0)
# endif /* !NULL */

/*
** SDL's macros
*/
# define SDL_SF(data)	((SDL_Surface *)(data))
# define SDL_VI(data)	((SDL_VideoInfo *)(data))

/*
** Thread
*/
int	create_thread();

/*
** GFX's structure
*/
  typedef struct	s_gfx
  {
    void		*screen;
    void		*infos;
    void		*image;
  }		t_gfx;

/*
** Init signal function
*/
void	init_signal(t_gfx *gfx);

/*
** GFX's functions
*/
int	init_screen(t_gfx *gfx);
void	destroy_screen(t_gfx *gfx);
int	loop_env(t_gfx *gfx);
int	catch_keys(void);

/*
** My
*/
void	my_putnbr(unsigned int n);
void	my_putstr(char *str);
void	my_putchar(char c);
int	my_strlen(char *str);
int	my_strcmp(char *s1, char *s2);

#endif /* __PHILO1_H__ */

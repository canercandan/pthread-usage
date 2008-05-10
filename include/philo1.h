/*
** philo1.h for philo1 in /home/candan_c/cu/rendu/project/philo1
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue May  6 15:45:38 2008 caner candan
** Last update Sat May 10 15:29:33 2008 caner candan
*/

#ifndef __PHILO1_H__
# define __PHILO1_H__

# define NB	7

# define SLEEP	0
# define THINK	1
# define EAT	2

# define RIGHT	0
# define LEFT	1

# define ST_SLEEP	1
# define ST_THINK	2
# define ST_EAT		4

/*
** Terminal's messages
*/
# define PWR_OFF_MESG	"\nPhilosOFF\n"

/*
** SDL's defines
*/
# define SCREEN_X	640
# define SCREEN_Y	480
# define DELAY		100

/*
** Backdrop's defines
*/
# define BACKDROP_FILE	"images/volcan.bmp"
# define BACKDROP_X	320
# define BACKDROP_Y	172

/*
** Character's defines
*/
# define CHARACTER_FILE		"images/bibi.bmp"
# define CHARACTER_MAX_PER_LINE	3
# define CHARACTER_X		32
# define CHARACTER_Y		48

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
** Character position's macros
*/
# define GET_CHARACTER_X(nbr)	(((nbr) % CHARACTER_MAX_PER_LINE) + 1)
# define GET_CHARACTER_Y(nbr)	(((nbr) / CHARACTER_MAX_PER_LINE) + 1)

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
  void		*character;
  void		*background;
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
** Character's functions
*/
int	create_character(t_gfx *gfx);
void	destroy_character(t_gfx *gfx);
void	set_character(t_gfx *gfx, int nbr, int x, int y);

/*
** My
*/
void	my_putnbr(unsigned int n);
void	my_putstr(char *str);
void	my_putchar(char c);
int	my_strlen(char *str);
int	my_strcmp(char *s1, char *s2);

#endif /* __PHILO1_H__ */

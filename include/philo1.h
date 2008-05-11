/*
** philo1.h for philo1 in /home/candan_c/cu/rendu/project/philo1
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue May  6 15:45:38 2008 caner candan
** Last update Sun May 11 11:55:53 2008 caner candan
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
# define DELAY		500
# define UNIT_X		5
# define UNIT_Y		5

/*
** Backdrop's defines
*/
# define BACKDROP_FILE	"images/arena.bmp"

/*
** Character's defines
*/
# define CHARACTER_FILE		"images/bibi.bmp"
# define CHARACTER_MAX_PER_LINE	3
# define CHARACTER_X		32
# define CHARACTER_Y		48

/*
** Status' defines
*/
# define STATUS_FILE		"images/status.bmp"
# define STATUS_MAX_PER_LINE	5
# define STATUS_X		17
# define STATUS_Y		17

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
** Position's macros
*/
# define GET_POSITION_X(nbr, max)	((nbr) % (max))
# define GET_POSITION_Y(nbr, max)	((nbr) / (max))

/*
** Useful's macros
*/
# define INFO(data)	((t_info *)(data))
# define GFX(data)	((t_gfx *)(data))

/* extern int	*gl_status; */
/* extern int	*gl_hp; */
/* extern void	*gl_stick; */

/*
** GFX's structure
*/
typedef struct	s_gfx
{
  void		*video;
  void		*infos;
  void		*backdrop;
  void		*character;
  void		*status;
}		t_gfx;

/*
** Infos' structure
*/
typedef struct	s_info
{
  char		id;
  char		nb_philos;
  char		nb_sticks;
  t_gfx		gfx;
  void		*threads;
  void		*stick;
  int		*hp;
  char		*status;
  char		mode_gfx;
  char		end;
}		t_info;

/*
** Position structure
*/
typedef struct	s_pos
{
  int		id;
  int		direction;
  int		x;
  int		y;
}		t_pos;

extern t_info	gl_info;

int	create_thread(int sdl_on);
void	print_status(int id);
int	get_id(int thread_id, int direction, int nb_philo);

/*
** Inits' function
*/
void	init_signal(void);
int	init_sdl(void);
int	parse_args(int ac, char **av);

/*
** GFX's functions
*/
int	init_screen(void);
void	destroy_screen(void);
int	loop_env(t_gfx *gfx);
int	catch_keys(void);
void	destroy_surface(void *surface);
int	create_video(t_gfx *gfx);

/*
** Backdrop's functions
*/
int	create_backdrop(t_gfx *gfx);
void	set_backdrop(t_gfx *gfx, int x, int y);

/*
** Character's functions
*/
int	create_character(t_gfx *gfx);
void	set_character(t_gfx *gfx, int nbr, int x, int y);

/*
** Status's functions
*/
int	create_status(t_gfx *gfx);
void	set_status(t_gfx *gfx, int nbr, int x, int y);

#endif /* __PHILO1_H__ */

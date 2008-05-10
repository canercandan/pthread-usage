/*
** philo1.h for philo1 in /home/candan_c/cu/rendu/project/philo1
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue May  6 15:45:38 2008 caner candan
** Last update Sat May 10 11:31:18 2008 caner candan
*/

#ifndef __PHILO1_H__
# define __PHILO1_H__

/*
** Infos' defines
*/
# define NB_PHILOS	7
# define NB_STICKS	7

/*
** Terminal's messages
*/
# define PWR_OFF_MESG	"\nPhilosOFF\n"

/*
** SDL's defines
*/
# define SCREEN_X	640
# define SCREEN_Y	480

/*
** Null's define
*/
# ifndef NULL
#  define NULL	((void *) 0)
# endif /* !NULL */

/*
** Macro useful
*/
# define INFO(data)	((t_info *) (data))
# define THR(data)	((t_thr *) (data))

/*
** SDL's macros
*/
# define SDL_SF(data)	((SDL_Surface *) (data))
# define SDL_VI(data)	((SDL_VideoInfo *) (data))

/*
** Threads' structure
*/
typedef struct	s_thr
{
  void		*thread;
  void		*mutex;
  void		*cond;
}		t_thr;

/*
** Infos' structure
*/
typedef struct	s_info
{
  void		*philo[NB_PHILOS];
  void		*stick[NB_STICKS];
  void		*cond_philo;
  void		*cond_sticks;
  t_thr		eat;
  t_thr		sleep;
  t_thr		think;
}		t_info;

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
** Initiations' functions
*/
void	init_actors(t_info *info);

/*
** Useful's functions
*/
void	launch_history(t_info *info);
void	destroy_actors(t_info *info);

/*
** Running's functions
*/
void	*philo_running(void *info);
void	*stick_running(void *info);

/*
** Init signal function
*/
void	init_signal(t_gfx *gfx);

/*
** GFX's functions
*/
int	init_screen(t_gfx *gfx);
void	destroy_screen(t_gfx *gfx);

#endif /* __PHILO1_H__ */

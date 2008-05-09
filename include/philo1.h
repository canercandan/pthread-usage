/*
** philo1.h for philo1 in /home/candan_c/cu/rendu/project/philo1
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue May  6 15:45:38 2008 caner candan
** Last update Fri May  9 16:34:30 2008 caner candan
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
** Initiations' functions
*/
void	init_actors(t_info *info);
void	init_signal(t_info *info);

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

#endif /* __PHILO1_H__ */

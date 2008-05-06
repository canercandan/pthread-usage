/*
** philo1.h for philo1 in /home/candan_c/cu/rendu/project/philo1
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue May  6 15:45:38 2008 caner candan
** Last update Tue May  6 15:48:15 2008 caner candan
*/

#ifndef __PHILO1_H__
# define __PHILO1_H__

/*
** TP's defines
*/
# define NB_TRAINS	6
# define TRAIN		'#'
# define WAY_FMT	"=====|----|=====\n"
# define WAY_SIZE	18
# define CRITIC_MIN	6
# define CRITIC_MAX	10

/*
** Null's define
*/
# ifndef NULL
#  define NULL	((void *) 0)
# endif /* !NULL */

/*
** Macro useful
*/
# define TP(data)		((t_tp *) (data))

/*
** TP's structure
*/
typedef struct	s_tp
{
  void		*train[NB_TRAINS];
  void		*bridge;
  void		*mutex_bridge;
  void		*cond_train;
  void		*cond_bridge;
}		t_tp;

#endif /* __PHILO1_H__ */

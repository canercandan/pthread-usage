/*
** tp.h for tp in /home/candan_c/cu/rendu/project/philo1/tp
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue May  6 07:49:16 2008 caner candan
** Last update Tue May  6 08:36:55 2008 caner candan
*/

#ifndef __TP_H__
# define __TP_H__

# define NB_TRAINS	3
# define TRAIN		'#'
# define WAY_FMT	"=====|----|=====\n"
# define WAY_SIZE	18
# define CRITIC_MIN	6
# define CRITIC_MAX	10

# ifndef NULL
#  define NULL		(void *) 0
# endif

# define PTHREAD(data)		(pthread_t *) (data)
# define PTHREAD_VALUE(data)	(pthread_t) (data)
# define PTHREAD_MUTEX(data)	(pthread_mutex_t *) (data)
# define PTHREAD_COND(data)	(pthread_cond_t *) (data)
# define TP(data)		(t_tp *) (data)

typedef struct	s_tp
{
  void		*train[NB_TRAINS];
  void		*bridge;
  void		*mutex_bridge;
  void		*cond_train;
  void		*cond_bridge;
}		t_tp;

#endif /* !__TP_H__ */

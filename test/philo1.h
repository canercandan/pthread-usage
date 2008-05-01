/*
** philo1.h for philo1 in /home/candan_c/cu/rendu/project/philo1/test
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu May  1 10:56:17 2008 caner candan
** Last update Thu May  1 13:05:50 2008 caner candan
*/

#ifndef __PHILO1_H__
# define __PHILO1_H__

/*
** Clients' defines
*/
# define NB_CLIENTS	5

/*
** NULL's define
*/
# ifndef NULL
#  define NULL	(void *) 0
# endif /* !NULL */

/*
** Thread values' structure
*/
typedef struct	s_mem
{
  void		*client[NB_CLIENTS];
  void		*stock;
  void		*mutex;
  int		qte;
}		t_mem;

/*
** Debug's functions
*/
void		debug(char *s, int pos);

#endif /* !__PHILO1_H__ */

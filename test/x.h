/*
** x.h for philo1 in /home/candan_c/cu/rendu/project/philo1/test
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu May  1 10:16:16 2008 caner candan
** Last update Fri May  2 09:36:07 2008 caner candan
*/

#ifndef __X_H__
# define __X_H__

/*
** Main functions of pthread
*/
int	xpthread_create(void *thread, const void *attr,
			void *(*start_routine)(void *), void *arg);
void	xpthread_exit(void *value_ptr);
int	xpthread_join(void *pthread, void **value_ptr);

/*
** Mutex's functions of pthread
*/
int	xpthread_mutex_init(void *mutex, const void *attr);
int	xpthread_mutex_destroy(void *mutex);
int	xpthread_mutex_trylock(void *mutex);
int	xpthread_mutex_unlock(void *mutex);

/*
** Condition's functions of pthread
*/
int	xpthread_cond_init(void *cond, const void *attr);
int	xpthread_cond_wait(void *cond, void *mutex);
int	xpthread_cond_signal(void *cond);
int	xpthread_cond_broadcast(void *cond);

#endif /* !__X_H__ */

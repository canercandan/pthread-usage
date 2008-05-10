/*
** x.h for philo1 in /home/candan_c/cu/rendu/project/philo1/include
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue May  6 15:02:27 2008 caner candan
** Last update Sat May 10 22:51:07 2008 florent hochwelker
*/

#ifndef __X_H__
# define __X_H__

/*
** Macros useful
*/
# define PTHREAD(data)			((pthread_t *)(data))
# define PTHREAD_VALUE(data)		((pthread_t)(data))
# define PTHREAD_MUTEX(data)		((pthread_mutex_t *)(data))
# define PTHREAD_ATTR(data)		((pthread_attr_t *)(data))
# define PTHREAD_MUTEXATTR(data)	((pthread_mutexattr_t *)(data))

/*
** Main functions of pthread
*/
int	xpthread_create(void *thread, const void *attr,
			void *(*start_routine)(void *), void *arg);

/*
** Mutex's functions of pthread
*/
int	xpthread_mutex_init(void *mutex, const void *attr);
int	xpthread_mutex_destroy(void *mutex);
int	xpthread_mutex_unlock(void *mutex);

/*
** Malloc's functions
*/
void	*xmalloc(int size);

#endif /* !__X_H__ */

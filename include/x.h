/*
** x.h for philo1 in /home/candan_c/cu/rendu/project/philo1/include
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue May  6 15:02:27 2008 caner candan
** Last update Sat May 10 20:26:32 2008 caner candan
*/

#ifndef __X_H__
# define __X_H__

/*
** Macros useful
*/
# define PTHREAD(data)			((pthread_t *) (data))
# define PTHREAD_VALUE(data)		((pthread_t) (data))
# define PTHREAD_MUTEX(data)		((pthread_mutex_t *) (data))
# define PTHREAD_COND(data)		((pthread_cond_t *) (data))
# define PTHREAD_ATTR(data)		((pthread_attr_t *) (data))
# define PTHREAD_CONDATTR(data)		((pthread_condattr_t *) (data))
# define PTHREAD_MUTEXATTR(data)	((pthread_mutexattr_t *) (data))

/*
** Main functions of pthread
*/
int	xpthread_create(void *thread, const void *attr,
			void *(*start_routine)(void *), void *arg);
void	xpthread_exit(void *value_ptr);
int	xpthread_join(void *thread, void **value_ptr);
int	xpthread_cancel(void *thread);

/*
** Mutex's functions of pthread
*/
int	xpthread_mutex_init(void *mutex, const void *attr);
int	xpthread_mutex_destroy(void *mutex);
int	xpthread_mutex_lock(void *mutex);
int	xpthread_mutex_unlock(void *mutex);

/*
** Condition's functions of pthread
*/
int	xpthread_cond_init(void *cond, const void *attr);
int	xpthread_cond_destroy(void *cond);
int	xpthread_cond_wait(void *cond, void *mutex);
int	xpthread_cond_signal(void *cond);
int	xpthread_cond_broadcast(void *cond);

/*
** Malloc's functions
*/
void	*xmalloc(int size);

#endif /* !__X_H__ */

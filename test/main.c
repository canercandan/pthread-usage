/*
** main.c for test in /u/epitech_2010s/candan_c/cu/rendu/c/philo1/test
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Wed Apr 30 07:03:40 2008 caner candan
** Last update Wed Apr 30 07:35:39 2008 caner candan
*/

#include <pthread.h>

void	*my_thread(void *arg)
{
  pthread_exit(NULL);
}

int			main(int ac, char **av)
{
  pthread_mutex_t	mutex;
  pthread_t		thread;

  pthread_mutex_init(&mutex, (void *) "coucou");
  pthread_create(&thread, NULL, my_thread, NULL);
  pthread_mutex_destroy(&mutex);
  pthread_exit(NULL);
  return (0);
}

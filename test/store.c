#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define INITIAL_STOCK   20
#define NB_CLIENTS      5

typedef struct	s_store
{
  int		stock;
  void		*thread_store;
  void		*thread_clients[NB_CLIENTS];
  void		*mutex_stock;
}		t_store;

void		debug(char *s)
{
  write(1, s, strlen(s));
  write(1, "\n", 2);
}

static int	get_random(int max)
{
  double	val;

  val = (double) max * rand();
  val = val / (RAND_MAX + 1.0);
  return ((int) val);
}

static void	*fn_store(void *p_data)
{
  while (1)
    {
      pthread_mutex_lock(p_data);
      if (gl_store.stock <= 0)
	{
	  gl_store.stock = INITIAL_STOCK;
	  printf("Remplissage du stock de %d articles !\n", gl_store.stock);
	}
      pthread_mutex_unlock(p_data);
    }
  return (NULL);
}

static void	*fn_clients(void *p_data)
{
  int		nb;
o  int		val;

  nb = (int) p_data;
  while (1)
    {
      pthread_mutex_lock(p_data);
      val = get_random(6);
      sleep(get_random(3));
      gl_store.stock -= val;
      printf("Client prend %d du stock, reste %d en stock !\n",
	     val, gl_store.stock);
      pthread_mutex_unlock(p_data);
    }
  return (NULL);
}

int			main(void)
{
  pthread_mutex_t	mutex;
  int			ret;
  int			i;

  printf("Creation du thread du magasin !\n");
  mutex = PTHREAD_MUTEX_INITIALIZER;
  debug("after initialise mutex");
  if (!(ret = pthread_create (&gl_store.thread_store, NULL, fn_store, NULL)))
    {
      printf("Creation des threads clients !\n");
      for (i = 0; i < NB_CLIENTS; i++)
	if ((ret = pthread_create(&gl_store.thread_clients[i], NULL,
				  fn_clients, (void *) &mutex)))
	  fprintf(stderr, "%s", strerror (ret));
    }
  else
    fprintf(stderr, "%s", strerror (ret));
  for (i = 0; i < NB_CLIENTS; i++)
    pthread_join(gl_store.thread_clients [i], NULL);
  pthread_join(gl_store.thread_store, NULL);
  return (0);
}

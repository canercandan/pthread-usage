##
## Makefile for philo1 in /home/candan_c/cu/rendu/project/philo1/test
## 
## Made by caner candan
## Login   <candan_c@epitech.net>
## 
## Started on  Thu May  1 10:36:00 2008 caner candan
## Last update Fri May  2 11:17:11 2008 caner candan
##

NAME		=	philo1

SRCS_X		=	xpthread_create.c		\
			xpthread_exit.c			\
			xpthread_join.c			\
			xpthread_mutex_destroy.c	\
			xpthread_mutex_init.c		\
			xpthread_mutex_trylock.c	\
			xpthread_mutex_unlock.c		\
			xpthread_cond_init.c		\
			xpthread_cond_destroy.c		\
			xpthread_cond_wait.c		\
			xpthread_cond_signal.c		\
			xpthread_cond_broadcast.c

SRCS		=	main.c		\
			debug.c

OBJS_X		=	$(SRCS_X:.c=.o)
OBJS		=	$(SRCS:.c=.o) $(OBJS_X)

INCLUDES	=	-I.
LIBRARY		=	-L. -lpthread

PANIC		=	-Wall -W -Werror -pedantic -ansi
DEBUG		=	-g

CFLAGS		=	$(INCLUDES) $(PANIC)
LDFLAGS		=	$(LIBRARY)

CC		=	gcc
RM		=	rm -f

all		:	$(NAME)

$(NAME)		:	$(OBJS)
			@$(CC) -o $@ $(OBJS) $(LDFLAGS)

clean		:
			$(RM) *~
			$(RM) *.o
			$(RM) *.core

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY		:	all clean fclean re

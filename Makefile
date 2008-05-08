##
## Makefile for make in /home/candan_c/cu/rendu/test/make
## 
## Made by caner candan
## Login   <candan_c@epitech.net>
## 
## Started on  Tue Apr 15 11:19:53 2008 caner candan
## Last update Thu May  8 15:09:03 2008 caner candan
##

NAME_APP	=	philo1
NAME_SRC	=	src
NAME_X		=	x
NAME_BIN	=	bin
NAME_OBJ	=	obj

PATH_SRC	=	$(NAME_SRC)/
PATH_X		=	$(NAME_X)/
PATH_BIN	=	$(NAME_BIN)/

BIN		=	$(PATH_BIN)$(NAME_APP)

SRCS_X		=	$(PATH_X)xpthread_create.c		\
			$(PATH_X)xpthread_exit.c		\
			$(PATH_X)xpthread_join.c		\
			$(PATH_X)xpthread_cancel.c		\
			$(PATH_X)xpthread_mutex_destroy.c	\
			$(PATH_X)xpthread_mutex_init.c		\
			$(PATH_X)xpthread_mutex_lock.c		\
			$(PATH_X)xpthread_mutex_unlock.c	\
			$(PATH_X)xpthread_cond_init.c		\
			$(PATH_X)xpthread_cond_destroy.c	\
			$(PATH_X)xpthread_cond_wait.c		\
			$(PATH_X)xpthread_cond_signal.c		\
			$(PATH_X)xpthread_cond_broadcast.c

SRCS		=	$(PATH_SRC)main.c		\
			$(PATH_SRC)init_signal.c	\
			$(PATH_SRC)init_actors.c	\
			$(PATH_SRC)launch_history.c	\
			$(PATH_SRC)destroy_actors.c

OBJS_X		=	$(SRCS_X:.c=.o)
OBJS		=	$(SRCS:.c=.o) $(OBJS_X)

INCLUDES	=	-I./include
LIBRARY		=	-L. -lpthread

DEBUG		=	-g
PANIC		=	-Wall -W -Werror -pedantic -ansi

CFLAGS		=	$(INCLUDES) $(PANIC) $(DEBUG)
LDFLAGS		=	$(LIBRARY)

CC		=	gcc
RM		=	rm -f
RM_O		=	find . -name '*.o' -exec rm {} \;
RM_TILD		=	find . -name '*~' -exec rm {} \;
RM_CORE		=	find . -name '*.core' -exec rm {} \;
MK		=	make
MKD		=	mkdir -p

.SUFFIXES	:	.c.o

all		:
			@$(MKD) $(PATH_BIN)
			@$(MK) $(BIN)

$(BIN)		:	$(OBJS)
			@$(MKD) $(PATH_SRC)
			@$(CC) -o $@ $(OBJS) $(LDFLAGS)

clean		:
			@$(RM_O)
			@$(RM_TILD)
			@$(RM_CORE)

fclean		:	clean
			$(RM) $(BIN)

re		:	fclean all

.PHONY		:	all clean fclean re

.c.o		:
			$(CC) $(CFLAGS) -c $< -o $@
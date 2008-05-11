##
## Makefile for make in /home/candan_c/cu/rendu/test/make
## 
## Made by caner candan
## Login   <candan_c@epitech.net>
## 
## Started on  Tue Apr 15 11:19:53 2008 caner candan
## Last update Sun May 11 15:29:00 2008 caner candan
##

NAME_APP	=	philo1
NAME_SRC	=	src
NAME_X		=	x
NAME_BIN	=	bin
NAME_OBJ	=	obj

PATH_SRC	=	$(NAME_SRC)/
PATH_MY		=	my/
PATH_X		=	$(NAME_X)/
PATH_BIN	=	$(NAME_BIN)/

BIN		=	$(PATH_BIN)$(NAME_APP)

SRCS_X		=	$(PATH_X)xpthread_create.c		\
			$(PATH_X)xpthread_mutex_destroy.c	\
			$(PATH_X)xpthread_mutex_init.c		\
			$(PATH_X)xpthread_mutex_unlock.c	\
			$(PATH_X)xmalloc.c

SRCS		=	$(PATH_SRC)main.c		\
			$(PATH_SRC)init_signal.c	\
			$(PATH_SRC)init_screen.c	\
			$(PATH_SRC)destroy_screen.c	\
			$(PATH_SRC)destroy_surface.c	\
			$(PATH_SRC)create_video.c	\
			$(PATH_SRC)loop_env.c		\
			$(PATH_SRC)create_character.c	\
			$(PATH_SRC)set_character.c	\
			$(PATH_SRC)print_status.c	\
			$(PATH_SRC)create_backdrop.c	\
			$(PATH_SRC)set_backdrop.c	\
			$(PATH_SRC)create_status.c	\
			$(PATH_SRC)set_status.c		\
			$(PATH_SRC)catch_keys.c		\
			$(PATH_SRC)create_thread.c	\
			$(PATH_SRC)get_id.c		\
			$(PATH_SRC)init_sdl.c		\
			$(PATH_SRC)parse_args.c		\
			$(PATH_SRC)power_off.c

SRCS_MY		=	$(PATH_MY)my_putnbr.c		\
			$(PATH_MY)my_putstr.c		\
			$(PATH_MY)my_strlen.c		\
			$(PATH_MY)my_strcmp.c		\
			$(PATH_MY)my_getnbr.c		\
			$(PATH_MY)my_putchar.c


OBJS_X		=	$(SRCS_X:.c=.o)
OBJS_MY		=	$(SRCS_MY:.c=.o)
OBJS		=	$(SRCS:.c=.o) $(OBJS_X) $(OBJS_MY)

INCLUDES_SDL	=	`pkg-config --cflags sdl`
LIBRARY_SDL	=	`pkg-config --libs sdl`

INCLUDES	=	-I./include $(INCLUDES_SDL)
LIBRARY		=	-L. -lpthread $(LIBRARY_SDL)

DEBUG		=	-g
PANIC		=	-Wall -W -Werror -pedantic -ansi -O2 -pipe

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
			$(MKD) $(PATH_BIN)
			$(MK) $(BIN)

$(BIN)		:	$(OBJS)
			$(MKD) $(PATH_SRC)
			$(CC) -o $@ $(OBJS) $(LDFLAGS)

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

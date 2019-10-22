# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rjeraldi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/21 21:58:57 by rjeraldi          #+#    #+#              #
#    Updated: 2019/10/22 15:07:28 by rjeraldi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
DEPS = *.h
DEPSDIR = includes
# SRC = *.c
SRC = main.c\
	  validator.c\
	  get_board_size.c\
	  blocks_handler.c\
	  tetr_init.c\
	  mem.c\
	  solver.c\
	  i.c\
	  j.c\
	  l.c\
	  o.c\
	  s.c\
	  t.c\
	  z.c
SRCDIR = srcs
OBJ = $(SRC:.c=.o)
CC = /usr/bin/gcc
CCFLAGS = -Wall -Wextra -Werror
RM = /bin/rm
RMFLAGS = -f
LIB = ft
LIBDIR = $(SRCDIR)/libft

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBDIR)
	$(CC) $(CCFLAGS) -I $(DEPSDIR) -I $(LIBDIR) -L $(LIBDIR) -l$(LIB) -o $(NAME) $^

$(OBJ): %.o : $(SRCDIR)/%.c $(DEPSDIR)/$(DEPS)
	$(CC) $(CCFLAGS) -I $(DEPSDIR) -I $(LIBDIR) -c -o $@ $<

$(SRCDIR)/$(SRC):

$(DEPSDIR)/$(DEPS):

clean:
	make -C $(LIBDIR) clean
	$(RM) $(RMFLAGS) $(OBJ)

fclean: clean
	make -C $(LIBDIR) fclean
	$(RM) $(RMFLAGS) $(NAME)

re: fclean all

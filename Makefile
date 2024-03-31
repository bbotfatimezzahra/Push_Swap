# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbbot <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/04 22:35:06 by fbbot             #+#    #+#              #
#    Updated: 2024/03/31 07:47:39 by fbbot            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
CFLAGS := -Wall -Wextra -Werror
SRCS := checkfunc.c headerfunc.c lstfunc.c fill_stack.c indexfunc.c\
	pushfunc.c rotatefunc.c movefunc.c actionfunc.c sort_stack.c cleanfunc.c\
	checkutil.c getnextline/get_next_line_utils.c getnextline/get_next_line.c\
	pushfunc_bonus.c rotatefunc_bonus.c
OBJS := $(SRCS:%.c=%.o)
LIB := pushswap.a
PROG := push_swap
CHECK := checker

.PHONY : all bonus clean fclean re 

.SECONDARY : $(OBJS)

all : $(PROG)

$(LIB) : $(OBJS)
	ar rc $(LIB) $(OBJS)

$(PROG) : $(LIB) main.c
	gcc main.c -o $(PROG) $(LIB)

bonus : $(CHECK) 

$(CHECK) : $(LIB) main_bonus.c
	gcc main_bonus.c -o $(CHECK) $(LIB)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(LIB) $(PROG) $(CHECK)

re : fclean all

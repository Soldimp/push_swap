# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 15:54:27 by nuno              #+#    #+#              #
#    Updated: 2023/02/21 17:20:20 by nuno             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g -fsanitize=address
RM		= rm -f

SRCS 	=  ${wildcard *.c}

OBJS	= $(SRCS:c=o)

all: $(NAME) 

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM)  $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:  fclean $(NAME)

.PHONY: all clean fclean re
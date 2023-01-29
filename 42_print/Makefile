# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nugarcia < nugarcia@student.42lisboa.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 11:59:09 by nugarcia          #+#    #+#              #
#    Updated: 2022/11/21 11:11:32 by nugarcia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = ft_numb ft_printf ft_words\

CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)
$(NAME) : $(SRC:=.o)
	ar rc $(NAME) $(SRC:=.o)
clean:
	$(RM) $(SRC:=.o)
fclean: clean
	$(RM) $(NAME)
re: fclean $(NAME)

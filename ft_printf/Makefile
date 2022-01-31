# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtambra <talya_1998@mail.ru>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/31 18:03:37 by jtambra           #+#    #+#              #
#    Updated: 2021/02/14 01:31:47 by jtambra          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c ft_utils.c ft_c_parse.c ft_diu_parse.c ft_num_utils.c \
		ft_p_parse.c ft_s_parse.c ft_type_parse.c ft_x_parse.c

HEADER = ft_printf.h

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror

CC = gcc

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c $(NAME)
	$(CC) $(FLAG) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

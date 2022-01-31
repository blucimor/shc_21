# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blucimor <blucimor@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/25 13:30:56 by blucimor          #+#    #+#              #
#    Updated: 2021/04/25 13:30:56 by blucimor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

FILE_PATH = "./map.cub"

LIBFT_PATH = ./libft
LIBFT_NAME = ft

LIBMX_PATH = ./minilibx_opengl
LIBMX_NAME = mlx

SRC = ./src/main.c \
	 ./src/calculations.c \
	 ./src/define.c \
	 ./src/general_tools.c \
	 ./src/grafic_tools.c \
	 ./src/grafic.c \
	 ./src/key_cmd.c \
	 ./src/mlx_cmd.c \
	 ./src/parser_map.c \
	 ./src/parser_set.c \
	 ./src/parser_spr.c \
	 ./src/parser.c \
	 ./src/screen.c \
	 ./src/struct_init.c

OBJ = ${SRC:.c=.o}

CFLAGS = -Wall -Wextra -Werror

MLXFLAGS = -framework OpenGL -framework Appkit

all: libs $(NAME)

%.o: %.c cub3d.h
	gcc $(CFLAGS) -c $< -o $@

libs:
	$(MAKE) -C $(LIBFT_PATH) all
	$(MAKE) -C $(LIBMX_PATH) all

start:
	./$(NAME) $(FILE_PATH)

$(NAME): $(OBJ)
	gcc $(OBJ) -L$(LIBFT_PATH) -l$(LIBFT_NAME) -L$(LIBMX_PATH) -l$(LIBMX_NAME) $(MLXFLAGS) -o $(NAME)

screen: $(NAME)
	./$(NAME) $(FILE_PATH) --save

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(MAKE) -C $(LIBMX_PATH) fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all start screen clean fclean re libs
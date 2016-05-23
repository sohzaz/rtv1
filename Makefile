# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbreton <dbreton@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/25 07:46:46 by dbreton           #+#    #+#              #
#*   Updated: 2016/05/16 15:43:50 by                  ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = RTv1 
OS = $(shell uname)
CFLAGS = -Wall -Wextra -Werror -O2 
SRC = main.c draw_tools.c win_draw.c win_init.c win_handlers.c parse.c
ifeq ($(OS), Darwin)
    MLX = mlx
    MFLAGS = -framework OpenGL -framework AppKit -lmlx -lm -lft
else ifeq ($(OS), Linux)
    MLX = mlx 
    MFLAGS = -lXext -lX11 -lm -lmlx -lft
endif

OBJ = $(SRC:.c=.o)

$(NAME) :
	make -C $(MLX)
	make -C libft
	gcc $(CFLAGS) -I $(MLX) -I libft/includes -c $(SRC)
	gcc $(CFLAGS) -L $(MLX) -L libft  $(OBJ) -o $(NAME) $(MFLAGS)

all : $(NAME)

clean :
	rm -f $(OBJ)
	#make -C libft clean
	#make -C $(MLX) clean

fclean : clean
	#make -C libft fclean
	rm -f $(NAME)

re : fclean all

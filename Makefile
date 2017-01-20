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
CFLAGS = -Wall -Wextra -Werror -g -O0
SRC = main.c draw_tools.c win_draw.c win_init.c win_handlers.c parse.c sphere.c plane.c vector.c vector2.c source.c sphere2.c color.c color2.c util.c cylinder.c cylinder2.c cone.c cone2.c matrix.c obj_type.c
ifeq ($(OS), Darwin)
    MLX = 
	I_MLX = 
    MFLAGS = -framework OpenGL -framework AppKit -lmlx -lm -lft
else ifeq ($(OS), Linux)
    MLX = -L mlx 
	I_MLX = -I mlx
    MFLAGS = -lXext -lX11 -lm -lmlx -lft
endif

OBJ = $(SRC:.c=.o)

$(NAME) :
	# make -C $(MLX)  
	make -C libft
	gcc $(CFLAGS) $(I_MLX) -I libft/includes -c $(SRC)
	gcc $(CFLAGS) $(MLX) -L libft  $(OBJ) -o $(NAME) $(MFLAGS) -Wl

all : $(NAME)

clean :
	rm -f $(OBJ)
	#make -C libft clean
	#make -C $(MLX) clean

fclean : clean
	#make -C libft fclean
	rm -f $(NAME)

re : fclean all

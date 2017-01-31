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
CFLAGS = -Wall -Wextra -Werror -g -O2
SRC = main.c draw_tools.c win_draw.c win_init.c parse.c sphere.c plane.c vector.c vector2.c source.c color.c color2.c util.c cylinder.c cone.c obj_type.c illumination.c parse2.c
SDL_PATH = "$(shell pwd)/sdl"
SDL_LIB = "$(SDL_PATH)/lib"
SDL_INCLUDE = "$(SDL_PATH)/include"
MFLAGS = -lft -lm -lSDL2

OBJ = $(SRC:.c=.o)
.PHONY: sdl clean

$(NAME) :
	# make -C $(MLX)
	make -C libft
	gcc $(CFLAGS) -I $(SDL_INCLUDE) -I libft/includes -c $(SRC)
	gcc $(CFLAGS) -L $(SDL_LIB) -L libft  $(OBJ) -o $(NAME) $(MFLAGS)

all : $(NAME)

clean :
	rm -f $(OBJ)
	#make -C libft clean
	#make -C $(MLX) clean

fclean : clean
	#make -C libft fclean
	rm -f $(NAME)

re : fclean all

sdl :
	cd sdl; \
	$(SDL_PATH)/configure --prefix=$(SDL_PATH)
	make -C $(SDL_PATH)
	make -C $(SDL_PATH) install

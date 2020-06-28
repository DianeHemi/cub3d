# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/26 14:17:45 by dchampda          #+#    #+#              #
#    Updated: 2020/06/26 14:17:47 by dchampda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	Cub3D

# --------- Gestion systeme --------- #
UNAME := $(shell uname)
ifeq ($(UNAME), Linux)
	MLX_DIR	= ./minilibx-linux
	MLX 	= -L $(MLX_DIR) -lmlx -lX11 -lXext -lm -lbsd
	ENV		= -D LINUX
	CC		=	clang
else
	MLX_DIR	= ./minilibx_opengl_20191021
	MLX 	= -L $(MLX_DIR) -lmlx -framework OpenGL -framework Appkit
	ENV		=
	CC		=	gcc
endif

CFLAGS	=	-Wall -Wextra -Werror

# --------- SRCS --------- #

# Main
SRCS 	+= ./srcs/cub3d.c

# Parsing
SRCS 	+= ./srcs/parsing/parsing.c

# bmp
SRCS 	+= ./srcs/bmp/

# Raytracing
SRCS 	+= ./srcs/raytracing/

# Utils
SRCS 	+= ./srcs/utils/

# --------- INC --------- #

INCLUDES	= ./includes/
HEADER		= $(INCLUDES)cub3d.h
INC_ALL		= -I$(INCLUDES) -I$(MLX_DIR)

# --------- OBJS --------- #

DIR_OBJS	= ./srcs/objs
OBJS		= $(SRCS:.c=$(DIR_OBJS).o)
#OBJSBONUS	= ${BONUS:.c=.o}

# --------- Compil --------- #

all: $(NAME)

$(NAME): $(OBJS) mlxcomp
	$(CC) $(CFLAGS) $(OBJS) $(INC_ALL) -o $@

.c.o: $(DIR_OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(ENV) -g -c $< -o ${<:.c=$(DIR_OBJS).o} $(INC_ALL)

$(DIR_OBJS):
	mkdir -p $@

mlxcomp:
	$(MAKE) -C $(MLX_DIR)

#bonus: ${OBJS} ${OBJSBONUS}

clean:
	$(MAKE) clean -C $(MLX_DIR)
	rm -R $(DIR_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE)

cleanbmp:
	rm bmp_saved/Cub3D_*

.PHONY all clean fclean re mlxcomp cleanbmp
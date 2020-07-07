# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/26 14:17:45 by dchampda          #+#    #+#              #
#    Updated: 2020/07/07 17:50:27 by dchampda         ###   ########.fr        #
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
SRCS 	+=	./srcs/parsing/parsing.c \
			./srcs/parsing/ft_get_walls.c \
			./srcs/parsing/ft_get_data.c \
			./srcs/parsing/ft_get_colors.c \
			./srcs/parsing/ft_get_map.c \
			./srcs/parsing/check_map.c

#GNL
SRCS 	+=	./srcs/gnl/get_next_line.c \
			./srcs/gnl/get_next_line_utils.c

# bmp
#SRCS 	+= ./srcs/bmp/

# Raytracing
#SRCS 	+= ./srcs/raytracing/

# Utils
SRCS 	+= ./srcs/utils/ft_atoi.c \
			./srcs/utils/ft_init.c \
			./srcs/utils/ft_split.c \
			./srcs/utils/ft_strchr.c \
			./srcs/utils/ft_strcmp.c \
			./srcs/utils/ft_strlen.c \
			./srcs/utils/ft_utils.c \
			./srcs/utils/ft_strncpy.c \
			./srcs/utils/ft_strdup.c \
			./srcs/utils/ft_strjoin2.c \
			./srcs/utils/ft_strnstr.c

# --------- INC --------- #

INCLUDES	= ./includes/
HEADER		= $(INCLUDES)cub3d.h
INC_ALL		= -I$(INCLUDES) 
# A remettre à la suite au dessus : -I$(MLX_DIR)

# --------- OBJS --------- #

DIR_OBJS	= ./srcs/objs/
OBJS		= $(SRCS:.c=.o)
#OBJSBONUS	= ${BONUS:.c=.o}

# --------- Compil --------- #

all: $(NAME)

$(NAME): $(DIR_OBJS) $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) $(INC_ALL) -o $@
	# A remettre après $(OBJS) : mlxcomp

$(DIR_OBJS)/%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -g -c $< -o ${<:.c=$(DIR_OBJS).o} $(INC_ALL)
	# A remettre après $(CFLAGS) : $(ENV)

$(DIR_OBJS):
	mkdir $(DIR_OBJS)

#mlxcomp:
#	$(MAKE) -C $(MLX_DIR)

#bonus: ${OBJS} ${OBJSBONUS}

clean:
	#$(MAKE) clean -C $(MLX_DIR)
	rm -R $(DIR_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE)

#cleanbmp:
#	rm bmp_saved/Cub3D_*

.PHONY : all clean fclean re mlxcomp cleanbmp

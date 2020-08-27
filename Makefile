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
	MLX 	= -L $(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd
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
SRCS 	+= ./srcs/raycasting/ft_launch_prog.c \
			./srcs/raycasting/raycasting.c \
			./srcs/raycasting/ft_draw.c \
			./srcs/raycasting/ft_move.c \
			./srcs/raycasting/ft_save.c \
			./srcs/raycasting/ft_sprite.c \
			./srcs/raycasting/ft_main_loop.c

# Utils
SRCS 	+= 	./srcs/utils/ft_init.c \
			./srcs/utils/ft_strcmp.c \
			./srcs/utils/ft_utils.c \
			./srcs/utils/ft_strncpy.c \
			./srcs/utils/ft_init_texture_sprite.c \
			./srcs/utils/ft_storage.c


# --------- INC --------- #

INCLUDES	= ./includes/
HEADER		= $(INCLUDES)cub3d.h
INC_ALL		= -I$(INCLUDES) -I$(MLX_DIR)
LIBFT		= ./libft/libft.a
LIBPATH		= ./libft

# --------- OBJS --------- #

OBJS		= $(SRCS:.c=.o)
#OBJSBONUS	= ${BONUS:.c=.o}





# --------- Compil --------- #

all: $(NAME)

$(NAME): $(LIB) $(OBJS) mlxcomp 
	$(CC) $(CFLAGS) $(OBJS) $(INC_ALL) -o $@ $(MLX) -L$(LIBPATH) -lft

$(LIB):
	make -C $(LIBPATH)

.c.o:
	$(CC) $(CFLAGS) $(ENV) -g -c $< -o ${<:.c=.o} $(INC_ALL)

mlxcomp:
	$(MAKE) -C $(MLX_DIR)

#bonus: ${OBJS} ${OBJSBONUS}

clean:
	$(MAKE) clean -C $(MLX_DIR)
	$(MAKE) clean -C $(LIBPATH)

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE)

#cleanbmp:
#	rm bmp_saved/Cub3D_*



.PHONY : all clean fclean re mlxcomp cleanbmp

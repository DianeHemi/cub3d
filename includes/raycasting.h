/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 12:50:36 by dchampda          #+#    #+#             */
/*   Updated: 2020/07/13 12:50:38 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include <math.h>



/*
** MACROS
*/
# ifdef __linux__

#  define ESC 		65307
#  define EXIT_BTN	33

#  ifndef QWERTY
#  define FORWD 	122
#  define BACKWD 	115
#  define LEFT 		113
#  define RIGHT 	100	
#  define TURN_L 	65363
#  define TURN_R 	65361
#  endif

#  ifdef QWERTY
#  define FORWD 	119
#  define BACKWD 	115
#  define LEFT 		97
#  define RIGHT 	100
#  define TURN_L 	68
#  define TURN_R 	67
#  endif
# endif



# ifdef __APPLE__
#  define FORWD 	13
#  define BACKWD 	1
#  define LEFT 		0
#  define RIGHT 	2
#  define TURN_L 	123
#  define TURN_R 	124
#  define ESC 		53
#  define EXIT_BTN	17
#  endif





/*
*** Stru1cture de la mlx
*/
typedef struct s_mlx
{
	void	*ptr;
	void	*win;
	char	*img;
	char	*img_ptr;
	int		bpp;
	int		size_line;
	int		endian;	
}			t_mlx;

/*
*** Structure du raycast
*/
typedef struct s_ray
{
	//player position
	double	pos_x;
	double	pos_y;
	//player direction
	double	dir_x;
	double	dir_y;
	//camera plane
	double	plane_x;
	double	plane_y; //fov
	//rayon
	double	rayDir_x;
	double	rayDir_y;
	double	cam_x;
	//carre dans lequel se trouve le rayon actuellement
	int		mapX;
	int		mapY;
	//Distance que le rayon doit parcourir depuis sa position de start
	//jusqu'à premier x-side & premier y-side
	double	sideDist_x;
	double	sideDist_y;
	//Distance que rayon parcourt d'un x-side au suivant ou y-side au suivant
	double	deltaDist_x;
	double	deltaDist_y;
	//calculer longueur du rayon
	double	perpWallDist;
	//Direction vers laquelle aller
	int		stepX;
	int		stepY;
	//Mur touche ? Orientation
	int		hit;
	int		side;
	//Direction du mur & donc sa couleur atm
	int		wallDir;
	//Where the wall is hit
	double	wallX;
	//Buffer pour sprites
	double	*zbuffer;
}			t_ray;


/*
*** Structure du drawer
*/
typedef struct s_draw
{
	int		lineHeight;
	int		drawStart;
	int		drawEnd;

	int		color;
	int 	x;
	int 	y;

	int 	dist;
	int 	side;

	double	step;
	double	tex_pos;
}			t_draw;


/*
*** Structure des textures
*/
typedef struct s_texture
{
	void	*ptr;
	char	*img;
	int		bpp;
	int		size_line;
	int		endian;

	int		width;
	int		height;

	int		tex_x;
	int		tex_y;
}			t_texture;



/*
*** Structure des sprites
*/
typedef struct s_sprite
{
	double		x;
	double		y;
}			t_sprite;

typedef struct s_sprite_data
{
	double 		x;
	double 		y;
	int 		d;

	double 		invDet;
	double 		dist;

	double 		transformX;
	double 		transformY;
	int 		screen_x;

	int 		factor_128;


	int 		s_height;
	int 		drawStart_y;
	int 		drawEnd_y;

	int 		s_width;
	int 		drawStart_x;
	int 		drawEnd_x;

	int 		tex_x;
	int 		tex_y;
	int 		color;
}			t_sprite_data;



/*
*** Structure deplacements
*/
typedef struct s_move
{
	int		forwd;
	int		backwd;
	int		left;
	int		right;
	int 	turn_l;
	int 	turn_r;

	//Deplacements
	double	mv_spd;
	double	rota_spd;
}			t_move;



/*
*** Structure globale du jeu
*/
typedef struct s_game
{
	t_config	*config;
	t_mlx		*mlx;
	t_ray		*ray;
	t_texture	*tex;
	t_sprite	*sprite;
	t_move		*move;
}			t_game;






/*
*** Stru1cture de la mlx
*/
typedef struct s_save
{
	int 		file_size;
	int 		reserved;
	int			offset;
	int 		header_size;
	short int 	planes;
	short int 	bpixels;
	int 		fd;

}			t_save;






/*
*** Fonctions
*/
int 	ft_launch_mlx(t_mlx *mlx, t_config *data);
int 	ft_launch_prog(t_config *config, t_mlx *mlx, int save_opt);
int 	ft_main_loop(t_game *game);

/*
*** Raycasting
*/
void	ft_raycasting(t_game *game);
void	ft_init_raycast(t_ray *ray, t_config *config, int x);
void	ft_calcul_step(t_ray *ray);
void	ft_dda_algo(t_ray *ray, t_config *config);
void	ft_get_wall_dist(t_ray *ray, int x);

/*
*** Drawing
*/
void	ft_init_drawing(t_ray *ray, t_config *config, t_draw *draw, int t_height);
void	ft_get_tex_coords(t_ray *ray, t_game *game);
void	ft_draw_colors(t_game *game, t_draw *draw);
void	my_mlx_pixel_put(t_mlx *mlx, int y, int x, int color);

/*
*** Key events
*/
int		ft_keypress(int keycode, t_game *game);
int		ft_keyrelease(int keycode, t_game *game);
void	ft_move_player(t_move *move, t_ray *ray, t_config *config);

int 	ft_exit(t_game *game);
void	ft_save(t_game *game);

/*
*** Sprites
*/
void	ft_sprite_management(t_game *game, t_config *config);


#endif
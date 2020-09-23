/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 12:50:36 by dchampda          #+#    #+#             */
/*   Updated: 2020/09/09 10:43:29 by dchampda         ###   ########.fr       */
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
#   define FORWD 	119
#   define BACKWD 	115
#   define LEFT 	97
#   define RIGHT 	100
#   define TURN_L 	65363
#   define TURN_R 	65361
#  endif

#  ifdef QWERTY
#   define FORWD 	119
#   define BACKWD 	115
#   define LEFT 	97
#   define RIGHT 	100
#   define TURN_L 	65363
#   define TURN_R 	65361
#  endif
# endif

# ifdef __APPLE__
#  define FORWD 	13
#  define BACKWD 	1
#  define LEFT 		0
#  define RIGHT 	2
#  define TURN_L 	124
#  define TURN_R 	123
#  define ESC 		53
#  define EXIT_BTN	17
# endif

/*
*** Stru1cture de la mlx
*/
typedef struct	s_mlx
{
	void	*ptr;
	void	*win;
	char	*img;
	char	*img_ptr;
	int		bpp;
	int		size_line;
	int		endian;
}				t_mlx;

typedef struct	s_pos
{
	double		x;
	double		y;
}				t_pos;

/*
*** Structure du raycast
*/
typedef struct	s_ray
{
	t_pos	pos;
	t_pos	dir;
	t_pos	ray_dir;
	double	cam_x;

	double	plane_x;
	double	plane_y;

	int		map_x;
	int		map_y;

	t_pos	side_dist;
	t_pos	delta_dist;
	double	wall_dist;

	int		step_x;
	int		step_y;

	int		hit;
	int		side;
	int		wall_dir;

	double	wall_x;
	double	*zbuffer;
}				t_ray;

/*
*** Structure du drawer
*/
typedef struct	s_draw
{
	int		line_height;
	int		draw_start;
	int		draw_end;

	int		color;
	int		x;
	int		y;

	int		dist;
	int		side;

	double	step;
	double	tex_pos;
}				t_draw;

/*
*** Structure des textures
*/
typedef struct	s_texture
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
}				t_texture;

/*
*** Structure des sprites
*/
typedef struct	s_s_pos
{
	double		x;
	double		y;
	double		dist;
}				t_s_pos;

typedef struct	s_sprite
{
	t_s_pos		*s_pos;
	double		x;
	double		y;
	int			d;

	double		ratio;

	double		inv_det;
	double		dist;
	t_pos		transform;
	int			screen_x;

	int			height;
	int			draw_start_y;
	int			draw_end_y;
	int			width;
	int			draw_start_x;
	int			draw_end_x;

	int			tex_x;
	int			tex_y;
	int			color;
}				t_sprite;

/*
*** Structure deplacements
*/
typedef struct	s_move
{
	int			forwd;
	int			backwd;
	int			left;
	int			right;
	int			turn_l;
	int			turn_r;
	double		mv_spd;
	double		rot_spd;
}				t_move;

/*
*** Structure globale du jeu
*/
typedef struct	s_game
{
	t_config	*config;
	t_mlx		*mlx;
	t_ray		*ray;
	t_texture	*tex;
	t_sprite	*sprite;
	t_move		*move;
}				t_game;

/*
*** Stru1cture sauvegarde
*/
typedef struct	s_save
{
	int			file_size;
	int			reserved;
	int			offset;
	int			header_size;
	short int	planes;
	short int	bpixels;
	int			fd;

}				t_save;

/*
*** Fonctions
*/
int				ft_init_image(t_config *config, t_mlx *mlx);
int				ft_launch_prog(t_config *config, t_mlx *mlx, int save_opt);
int				ft_main_loop(t_game *game);

/*
*** Raycasting
*/
void			ft_raycasting(t_game *game);
void			ft_init_raycast(t_ray *ray, t_config *config, int x);
void			ft_calcul_step(t_ray *ray);
void			ft_dda_algo(t_ray *ray, t_config *config);
void			ft_get_wall_dist(t_ray *ray, int x);

/*
*** Drawing
*/
void			ft_init_drawing(t_ray *ray, t_config *config,
				t_draw *draw, int tex_height);
void			ft_get_tex_coords(t_ray *ray, t_game *game);
void			ft_draw_colors(t_game *game, t_draw *draw);
void			ft_sprite_management(t_game *game, t_sprite *spr,
				t_config *config);

/*
*** Key events
*/
int				ft_keypress(int keycode, t_game *game);
int				ft_keyrelease(int keycode, t_game *game);
void			ft_move_player(t_move *move, t_ray *ray, t_config *config);
int				ft_exit(t_game *game);
void			ft_save(t_game *game);

#endif

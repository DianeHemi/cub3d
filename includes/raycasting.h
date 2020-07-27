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



/*
*** Structure de la mlx
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

	//Mur touche ?
	int		hit;
	//Orientation du mur
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
	//lowest & highest pixel
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
	double		pos_x;
	double		pos_y;


}			t_sprite;




/*
*** Structure deplacements
*/
typedef struct s_move
{
	int		forwd;
	int		backwd;
	int		left;
	int		right;

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
	t_draw		*draw;
}			t_game;




/*
*** Fonctions
*/
int 	ft_launch_prog(t_config *config, t_mlx *mlx);
int 	ft_main_loop(t_game *game);

void	ft_init_raycast(t_ray *ray, t_config *config, int x);
void	ft_calcul_step(t_ray *ray);
void	ft_dda_algo(t_ray *ray, t_config *config);
void	ft_get_wall_dist(t_ray *ray, int x);


#endif
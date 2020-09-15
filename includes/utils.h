/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 11:47:56 by dchampda          #+#    #+#             */
/*   Updated: 2020/07/07 17:50:45 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "raycasting.h"
#include <X11/Xlib.h>
#include "mlx_int.h"


/*
*** Fonctions relatives a exit
*/
void	ft_free_tab(char **str);
int 	ft_exit(t_game *game);
void 	ft_free_tex(t_config *config);

void	my_mlx_pixel_put(t_mlx *mlx, int y, int x, int color);
int		ft_errors(char *str);

/*
*** Utilitaires
*/
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strncpy(char *src, char *dest, int len);


/*
*** Initialisation des structures
*/
void 	ft_init_config(t_config *config);
void	ft_init_player_pos(t_config *config, t_ray *ray);
void	ft_set_dir(t_ray *ray, double x, double y);
int 	ft_init_textures(t_config *data, t_game *game,
						t_texture *texture, t_mlx *mlx);


void	ft_get_pos_sprite(t_sprite *spr, t_config *data);
int 	ft_get_nb_sprite(t_config *data);


int		ft_store_struct(t_config *data, t_ray *ray, 
						t_mlx *mlx, t_game *game);


void	ft_init_tex_struct(t_game *game);
void	ft_init_move(t_move *move, t_game *game);


void		ft_sort_sprites(t_game *game, int nb_sprite);
double		ft_sprite_dist(t_ray *ray, t_s_pos *sprite);


#endif
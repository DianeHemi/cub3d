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
/*
*** Compare 2 strings
*/
int		ft_strcmp(const char *s1, const char *s2);

/*
*** Cherche mot dans phrase
*/
char	*ft_strnstr(const char *s1, const char *s2, size_t len);

char	*ft_strchr(const char *s, int c);

size_t	ft_strlen(const char *s);
int		ft_atoi(const char *nptr);
char	**ft_split(char const *s, char c);
char	*ft_strncpy(char *src, char *dest, int len);
char	*ft_strdup(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);

/*
*** Initialisation des structures
*/
void 	ft_init_config(t_config *config);
void	ft_init_player_pos(t_config *config, t_ray *ray);
void	ft_set_dir(t_ray *ray, int x, int y);
int 	ft_init_textures(t_config *data, t_game *game,
						t_texture *texture, t_mlx *mlx);


void	ft_get_pos_sprite(t_sprite *sprite, t_config *data, t_game *game);
int 	ft_get_nb_sprite(t_config *data);


void	ft_init_store(t_config *data, t_ray *ray, 
						t_mlx *mlx, t_game *game);
void	ft_init_tex_struct(t_game *game);

/*
*** Liberation memoire sur tableaux
*/
void	ft_free_tab(char **str);


#endif

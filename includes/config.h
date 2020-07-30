/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 11:39:58 by dchampda          #+#    #+#             */
/*   Updated: 2020/07/28 17:52:38 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# include "get_next_line.h"

/*
 *** Structure pour les infos de la map 
*/
typedef	struct s_config
{
	int			width;
	int			height;

	char		**map;

	char		north_tex[256];
	char		south_tex[256];
	char		west_tex[256];
	char		east_tex[256];
	char		sprite_tex[256];

	int			f_color;
	int			c_color;

	int			player_x;
	int			player_y;
	char		player_start;

	int			nb_sprite;

}				t_config;


/*
*** Fonctions
*/
int		get_next_line(int fd, char **line);

/*
*** Fonctions de parsing
*/
int		ft_parsing(char *map, t_config *data);

/*
*** Recuperation des donnees
*/
int		ft_get_config(t_config *config, char *line);
int		ft_get_colors(t_config *config, char *line);
int		ft_get_resolution(t_config *config, char *line);

int 	ft_get_wall_north(t_config *config, char *line);
int 	ft_get_wall_south(t_config *config, char *line);
int		ft_get_wall_east(t_config *config, char *line);
int 	ft_get_wall_west(t_config *config, char *line);
int		ft_get_sprite(t_config *config, char *line);

int		ft_get_map(int fd, char *line, t_config *config);
int 	ft_get_player_pos(t_config *config, int y, int x);

/*
*** Verification des donnees
*/
int		ft_check_config(t_config *config);
int		ft_check_map(t_config *config);
int		ft_open_tex(t_config *config);

/*
*** Est-ce que la ligne contient une map ?
*/
int		ft_is_map(char *line);


#endif

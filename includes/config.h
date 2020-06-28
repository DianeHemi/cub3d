/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 11:39:58 by dchampda          #+#    #+#             */
/*   Updated: 2020/06/26 11:40:41 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# include <fcntl.h>
# include "./get_next_line.h"

/*
*** Fichier header du parsing
*/


/*
 *** Structure pour les infos de la map 
*/
typedef	struct s_config
{
	int		width;
	int		height;

	char	**map;
	// int/char pour map ?

	char	no_text;	//Textures des murs
	char	so_tex;
	char	we_tex;
	char	ea_tex;
	char	s_tex;

	int		f_color;	//Couleurs du plafond et sol
	int		c_color;

}		t_config;


/*
*** Fonctions
*/
int		get_next_line(int fd, char **line);



#endif

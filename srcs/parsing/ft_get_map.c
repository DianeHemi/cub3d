/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 19:05:03 by dchampda          #+#    #+#             */
/*   Updated: 2020/07/01 19:05:06 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_get_map(int fd, char *line, t_config *config)
{
	int		read;
	char	*map_tmp;

	read = 0;

	//Lire les lignes 1 par 1 et les copier ?


	//Copier contenu de la 1ere ligne qu'on a encore en stock
	//Puis lire avec while et copier au fur et a mesure
	while ((read = get_next_line(fd, &line)) > 0)
	{

	}



	free(line);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 15:02:05 by dchampda          #+#    #+#             */
/*   Updated: 2020/07/02 16:23:12 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int ft_get_wall_north(t_config *config, char *line)
{
	int i;
	int j;

	i = 0;
	if (config->north_tex[0] != '\0')
		return (ft_errors("Duplicate north wall texture declared.\n"));
	while (line[i] == ' ' && line[i] != '\0')
		i++;
	j = i;
	while (line[j] != ' ' && line[j] != '\0')
		j++;
	ft_strncpy(&line[i], config->north_tex, j - i);
	return (1);
}

int ft_get_wall_south(t_config *config, char *line)
{
	int i;
	int j;

	i = 0;
	if (config->south_tex[0] != '\0')
		return (ft_errors("Duplicate south wall texture declared.\n"));
	while (line[i] == ' ' && line[i] != '\0')
		i++;
	j = i;
	while (line[j] != ' ' && line[j] != '\0')
		j++;
	ft_strncpy(&line[i], config->south_tex, j - i);
	return (1);
}


int ft_get_wall_east(t_config *config, char *line)
{
	int i;
	int j;

	i = 0;
	if (config->east_tex[0] != '\0')
		return (ft_errors("Duplicate east wall texture declared.\n"));
	while (line[i] == ' ' && line[i] != '\0')
		i++;
	j = i;
	while (line[j] != ' ' && line[j] != '\0')
		j++;
	ft_strncpy(&line[i], config->east_tex, j - i);
	return (1);
}

int ft_get_wall_west(t_config *config, char *line)
{
	int i;
	int j;

	i = 0;
	if (config->west_tex[0] != '\0')
		return (ft_errors("Duplicate west wall texture declared.\n"));
	while (line[i] == ' ' && line[i] != '\0')
		i++;
	j = i;
	while (line[j] != ' ' && line[j] != '\0')
		j++;
	ft_strncpy(&line[i], config->west_tex, j - i);
	return (1);
}

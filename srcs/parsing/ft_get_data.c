/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 14:58:39 by dchampda          #+#    #+#             */
/*   Updated: 2020/06/30 14:58:56 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_get_resolution(t_config *config, char *line)
{
	int i;

	i = 0;
	if (config->width != 0 || config->height != 0)
		return (ft_errors("Duplicate resolution data.\n"));
	while (line[i] == ' ')
		i++;
	config->width = ft_atoi(&line[i]);
	while (line[i] != ' ')
		i++;
	config->height = ft_atoi(&line[i]);
	return (1);
}

int	ft_get_sprite(t_config *config, char *line)
{
	int i;
	int j;

	i = 0;
	if (config->sprite_tex[0] != '\0')
		return (ft_errors("Duplicate sprite declared.\n"));
	while (line[i] == ' ' && line[i] != '\0')
		i++;
	j = i;
	while (line[j] != ' ' && line[j] != '\0')
		j++;
	ft_strncpy(&line[i], config->sprite_tex, j - i);
	return (1);
}



int	ft_open_tex(t_config *config)
{
	(void)config;

	return (1);
}
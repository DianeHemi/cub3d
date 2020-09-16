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

int	ft_get_wall_north(t_config *config, char *line)
{
	int start;
	int end;

	start = 0;
	if (config->north_tex != NULL)
		return (ft_errors("Duplicate north wall texture declared.\n"));
	while (line[start] == ' ' && line[start] != '\0')
		start++;
	end = start;
	while (line[end] != ' ' && line[end] != '\0')
		end++;
	if (line[end] != '\0')
		end++;
	config->north_tex = ft_substr(line, start, end - start - 1);
	return (1);
}

int	ft_get_wall_south(t_config *config, char *line)
{
	int start;
	int end;

	start = 0;
	if (config->south_tex != NULL)
		return (ft_errors("Duplicate south wall texture declared.\n"));
	while (line[start] == ' ' && line[start] != '\0')
		start++;
	end = start;
	while (line[end] != ' ' && line[end] != '\0')
		end++;
	if (line[end] != '\0')
		end++;
	config->south_tex = ft_substr(line, start, end - start - 1);
	return (1);
}

int	ft_get_wall_east(t_config *config, char *line)
{
	int start;
	int end;

	start = 0;
	if (config->east_tex != NULL)
		return (ft_errors("Duplicate east wall texture declared.\n"));
	while (line[start] == ' ' && line[start] != '\0')
		start++;
	end = start;
	while (line[end] != ' ' && line[end] != '\0')
		end++;
	if (line[end] != '\0')
		end++;
	config->east_tex = ft_substr(line, start, end - start - 1);
	return (1);
}

int	ft_get_wall_west(t_config *config, char *line)
{
	int start;
	int end;

	start = 0;
	if (config->west_tex != NULL)
		return (ft_errors("Duplicate west wall texture declared.\n"));
	while (line[start] == ' ' && line[start] != '\0')
		start++;
	end = start;
	while (line[end] != ' ' && line[end] != '\0')
		end++;
	if (line[end] != '\0')
		end++;
	config->west_tex = ft_substr(line, start, end - start - 1);
	return (1);
}

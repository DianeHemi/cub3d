/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 12:43:00 by dchampda          #+#    #+#             */
/*   Updated: 2020/07/01 12:43:02 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int			ft_rgb_conv(int nb[3], int i)
{
	if (nb[0] > 255 || nb[1] > 255 || nb[2] > 255)
		return (-1);
	else if (nb[0] < 0 || nb[1] < 0 || nb[2] < 0)
		return (-1);
	else
		nb[i] = 65536 * nb[0] + 256 * nb[1] + nb[2];
	return (nb[i]);
}

int			ft_check_nb(char *str)
{
	int i;

	i = 0;
	if (str[i] == '\n')
		return (0);
	while (str[i])
	{
		if (!ft_strchr("0123456789\n", str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	ft_treat_errors(char **color)
{
	ft_free_tab(color);
	return (-1);
}

int			ft_rgb_to_int(char *line)
{
	int		nb[4];
	char	**color;
	int		i;

	i = 0;
	while (line[i] == ' ')
		i++;
	color = ft_split(&line[i], ',');
	while (color[i])
		i++;
	if (i > 3 || i < 3)
		return (ft_treat_errors(color));
	i = 0;
	while (i < 3)
	{
		if (color[i] == NULL || !ft_check_nb(color[i]))
			return (ft_treat_errors(color));
		else
			nb[i] = ft_atoi(color[i]);
		i++;
	}
	ft_free_tab(color);
	nb[i] = ft_rgb_conv(nb, i);
	return (nb[i]);
}

int			ft_get_colors(t_config *config, char *line)
{
	if (line[0] == 'F' && config->f_color == -2)
		config->f_color = ft_rgb_to_int(&line[1]);
	else if (line[0] == 'C' && config->c_color == -2)
		config->c_color = ft_rgb_to_int(&line[1]);
	else
		return (ft_errors("Error\nDuplicate colors data.\n"));
	if (config->f_color == -1 || config->c_color == -1)
		return (ft_errors("Error\nWrong color format, it must be 'R,G,B'.\n"));
	return (1);
}

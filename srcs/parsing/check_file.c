/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 11:43:31 by dchampda          #+#    #+#             */
/*   Updated: 2020/06/29 17:19:08 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_check_line(t_cub3d data, char *line)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == 'R')
		{
		}
		else if (line[i] == 'F' || line[i] == 'C')
		{
		}
		else if () //Trouver NO, SO, WE, EA et S
		{
		}
		else if (line[i] == '1' || line[i] == '0')
			return (2);
		else
			i++;
	}
	return (1);
}

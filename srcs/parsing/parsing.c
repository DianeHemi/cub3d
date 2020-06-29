/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 11:43:49 by dchampda          #+#    #+#             */
/*   Updated: 2020/06/29 17:18:50 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/config.h"

int	ft_read_config(int fd, t_cub3d data)
{
	char	*line;
	int		check_args;
	int		check_map;

	check_args = 0;
	check_map = 0;
	while (get_next_line(fd, line) > 0)
	{
		if (ft_check_line(data, line) == 0)
			return (0);
		else if (ft_check_line(data, line) == 2)
			check_map = ft_check_map();
		else
			check_args += 1;
	}

	/*
	*** Ici check que la config est valide
	*/
	if (check_args != 8 || !ft_check_args(    )) //ft_check_args a faire
		return (ft_errors("Error: Configuration is invalid\n"));
	else if (check_map != 1)
		return (ft_errors("Error: Map is invalid\n"));
	else	
		return (1);
}



int	ft_parsing(char *map, int save_option t_cub3d data)
{
	t_cub data;
	int	fd;	

	if (fd = open(map, O_RDONLY) < 0)
		return (ft_errors("Error: cannot open map\n"));
	if (!ft_read_config(fd, data))
		return (ft_errors("Error: Invalid map\n"));
	
	

			

	return ();
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 11:45:57 by dchampda          #+#    #+#             */
/*   Updated: 2020/07/07 15:51:08 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_errors(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	return (0);
}

int ft_check_extension(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 1] != 'b' && str[i - 2] != 'u' && str[i - 3] != 'c'
		&& str[i - 4] != '.')
		return (0);
	else 
		return (1);
}

int	ft_check_args(int argc, char **argv, int *save_opt)
{
	if (argc < 2 || argc > 3)
		return (ft_errors("Wrong format : ./exec map.cub (--save)\n"));
	if (argc == 3)
	{
		if (ft_strcmp(argv[2], "--save") != 0 
			|| !ft_check_extension(argv[1]))
			return (ft_errors("Error : invalid arguments\n"));
		else
		{
			*save_opt = 1;
			return (1);
		}
	}
	else
	{
		if (!ft_check_extension(argv[1]))
			return (ft_errors("Invalid format : Select a .cub map\n"));
		else
			return (1);
	}
}

int	main(int argc, char **argv)
{
	int			save_opt;
	t_config	config;
	t_mlx		mlx;

	save_opt = 0;
	if (!ft_check_args(argc, argv, &save_opt))
		return (EXIT_FAILURE);
	ft_init_config(&config);
	if (!ft_parsing(argv[1], &config))
		return (EXIT_FAILURE);
	if (!ft_check_config(&config))
	{
		ft_free_tab(config.map);
		ft_errors("Error : Configuration is invalid.\n");
		return (EXIT_FAILURE);
	}
	if (!ft_launch_mlx(&mlx, &config))
		return (EXIT_FAILURE);
	if (!ft_launch_prog(&config, &mlx, save_opt))
		return (EXIT_FAILURE);

	return (0);
}

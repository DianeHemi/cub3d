/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 11:45:57 by dchampda          #+#    #+#             */
/*   Updated: 2020/06/29 16:31:21 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_errors(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
	{
		write(2, &str[i], 1);
		i++;
	}
	return (0);
}

int	ft_check_args(int argc, char **argv, int *save_option)
{
	if (argc < 2 || argc > 3)
		return (ft_errors("Wrong format : ./exec map.cub (--save)\n"));
	if (argc == 3)
	{
		if (ft_strncmp(argv[2], "--save") != 0 
			|| ft_strnstr(argv[1], ".cub", ft_strlen(argv[1])) == 0)
			return (ft_errors("Error : invalid arguments\n"));
		else
		{
			*save_option = 1; //save a gerer dans autre fonction
			return (1);
		}
	}
	else
	{
		if (ft_strnstr(argv[1], ".cub", ft_strlen(argv[1])) == 0)
			return (ft_errors("Invalid format : Select a .cub map\n"));
		else
			return (1);
	}
}

int	main(int argc, char **argv)
{
	int		save_option;
	t_cub3d	data;

	save_option = 0;
	if (!(data = malloc(sizeof(t_cub)))) // ++ Malloc la structure !!
		return (EXIT_FAILURE);	
	if (!ft_check_args(argc, argv, &save_option))
		return (EXIT_FAILURE);	//Affichage des erreurs sur les arguments
	if (!ft_parsing(argv[1]), save_option, data)
		return (EXIT_FAILURE);    //Affichage des erreurs sur fichier et parsing sera gere dans ft_parsing + save ?



/*
*** Gestion ouverture fenetre et affichage
*/

	return (0);
}

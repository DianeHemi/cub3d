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
		if (ft_strcmp(argv[2], "--save") != 0 
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



#include <stdio.h> //
int	main(int argc, char **argv)
{
	int			save_option;
	t_config	config;

	save_option = 0;
	ft_init_config(&config);
	if (!ft_check_args(argc, argv, &save_option))
		return (EXIT_FAILURE);	//Affichage des erreurs sur les arguments
	if (!ft_parsing(argv[1], &config))
		return (EXIT_FAILURE);	//Affichage des erreurs sur fichier et parsing sera gere dans ft_parsing + save ?


	printf("\n\nResolution : W %d H %d\n", config.width, config.height);
	printf("Colors : F %d C %d\n", config.f_color, config.c_color);
	printf("Sprite : %s\n", config.sprite_tex);
	printf("North wall : %s\nSouth wall : %s\n", config.north_tex, config.south_tex);
	printf("East wall : %s\nWest wall : %s\n", config.east_tex, config.west_tex);
	printf("\n");
	for (int i = 0; config.map[i] != '\0'; i++)
		printf("Map : %s\n", config.map[i]);
	printf("\n\n");
	

// Fonction separee pour lancer le prog et initialiser les structs ?

/*
*** Gestion ouverture fenetre et affichage
*/

	return (0);
}

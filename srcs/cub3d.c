/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 11:45:57 by dchampda          #+#    #+#             */
/*   Updated: 2020/06/25 16:42:03 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../libft/libft.h"

int	ft_check_args(int argc, char **argv)
{
	if (argc < 2 || argc > 3)
	{
		write(2, "Wrong format : ./exec map.cub (--save)\n", 39);
		return (0);
	}
	if (argc == 3)
	{
		if (ft_strncmp(argv[2], "--save") != 0)
		{
			write(2, "Error : --save to save screen\n", 31);
			return (0);
		}
		else
		{
			//Lancement fonction de sauvegarde
			//return (1);
		}
	}
	else
	{
		if (ft_strchr(argv[1], ".cub") == XX) //Fonction pour trouver mot dans phrase
		{
			write(2, "Invalid format : Select a .cub map\n", 35);
			return (0);
		}
		else
			return (1);  //Tout est bon, on passe au parsing de la map
	}
}

int	main(int argc, char **argv)
{



	if (!ft_check_args(argc, argv))
		return (-1);	//Affichage des erreurs sur les arguments


	if (!ft_parsing(argv[1]))
		return (-1);    //Affichage des erreurs sur fichier et parsing sera gere dans ft_parsing




	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch_prog.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 12:49:35 by dchampda          #+#    #+#             */
/*   Updated: 2020/07/13 12:49:40 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"




int ft_launch_prog(t_config *data, t_mlx *mlx)
{

//Construire univers ? Recup position murs et sprites ?
//Recup 


	if ((mlx->ptr = mlx_init()) == NULL)
		return (ft_errors("Initialisation failed.\n"));
	if (!(mlx->win = mlx_new_window(mlx->ptr, data->width, data->height, "Cub3D")))
		return (ft_errors("Window couldn't be initialised.\n"));
	//mlx_loop(mlx->ptr);
	return (1);
}
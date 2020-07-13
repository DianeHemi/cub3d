/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 12:50:36 by dchampda          #+#    #+#             */
/*   Updated: 2020/07/13 12:50:38 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H



/*
*** Structure de la mlx
*/
typedef struct s_mlx
{
	void	*ptr;
	void	*win;

}			t_mlx;




int ft_launch_prog(t_config *config, t_mlx *mlx);


#endif
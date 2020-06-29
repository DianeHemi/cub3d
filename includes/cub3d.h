/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 11:46:45 by dchampda          #+#    #+#             */
/*   Updated: 2020/06/29 16:29:25 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <mlx.h>
# include "./config.h"  //Header parsing
# include "./utils.h"	//Remplace la libft





/*
** MACROS
*/



/*
 *** Structure generale, contenant autres structs
*/
typedef	struct s_struct
{
	t_config	map;



}		t_cub3d;






/*
*** Fonctions
*/

/*
*** Affichage des erreurs
*/
int	ft_errors(char *str);



#endif

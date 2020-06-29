/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 11:47:56 by dchampda          #+#    #+#             */
/*   Updated: 2020/06/29 14:45:19 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include <unistd.h>

/*
*** Compare 2 strings
*/
int		ft_strcmp(const char *s1, const char *s2);

/*
*** Cherche mot dans phrase
*/
char	*ft_strnstr(const char *s1, const char *s2, size_t len)


size_t	ft_strlen(const char *s)


#endif
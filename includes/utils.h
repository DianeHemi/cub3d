/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 11:47:56 by dchampda          #+#    #+#             */
/*   Updated: 2020/07/07 16:31:53 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/*
*** Compare 2 strings
*/
int		ft_strcmp(const char *s1, const char *s2);

/*
*** Cherche mot dans phrase
*/
char	*ft_strnstr(const char *s1, const char *s2, size_t len);

char	*ft_strchr(const char *s, int c);

size_t	ft_strlen(const char *s);
int		ft_atoi(const char *nptr);
char	**ft_split(char const *s, char c);
char	*ft_strncpy(char *src, char *dest, int len);
char	*ft_strdup(const char *s);

/*
*** Initialisation des structures
*/
void 	ft_init_config(t_config *config);

/*
*** Liberation memoire sur tableaux
*/
void	ft_free_tab(char **str);


#endif

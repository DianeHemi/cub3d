/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 12:20:56 by dchampda          #+#    #+#             */
/*   Updated: 2020/07/07 15:31:20 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

int		get_next_line(int fd, char **line);
int		find_n(char *buffer, char c);
size_t	ft_strlen(char const *str);
char	*ft_strndup(char *str, int len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*copy_after_n(char *str, int len);

#endif

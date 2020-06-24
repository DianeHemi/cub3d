/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 19:33:36 by dchampda          #+#    #+#             */
/*   Updated: 2020/04/29 19:55:30 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_struct;

	if (!(new_struct = malloc(sizeof(t_list))))
		return (NULL);
	new_struct->content = content;
	new_struct->next = NULL;
	return (new_struct);
}

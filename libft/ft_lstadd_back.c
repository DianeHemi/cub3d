/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 11:11:51 by dchampda          #+#    #+#             */
/*   Updated: 2020/04/30 11:21:01 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*last_elemt;

	if (!*alst)
	{
		*alst = new;
		return ;
	}
	last_elemt = ft_lstlast(*alst);
	last_elemt->next = new;
}

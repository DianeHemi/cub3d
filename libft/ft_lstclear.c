/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 13:38:36 by dchampda          #+#    #+#             */
/*   Updated: 2020/05/10 15:07:20 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*old_lst;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		del((*lst)->content);
		old_lst = *lst;
		*lst = old_lst->next;
		free(old_lst);
	}
	*lst = NULL;
}

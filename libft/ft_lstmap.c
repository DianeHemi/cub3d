/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 11:46:39 by dchampda          #+#    #+#             */
/*   Updated: 2020/05/10 15:08:56 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *dest;
	t_list *tmp;

	dest = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		if (!(tmp = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&dest, del);
			return (NULL);
		}
		ft_lstadd_back(&dest, tmp);
		lst = lst->next;
	}
	return (dest);
}

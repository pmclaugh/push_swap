/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmclaugh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 23:04:41 by pmclaugh          #+#    #+#             */
/*   Updated: 2016/11/30 17:40:50 by pmclaugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ftlist	*ft_lstmap(t_ftlist *lst, t_ftlist *(*f)(t_ftlist *elem))
{
	t_ftlist *newlist;
	t_ftlist *newlisthead;

	if (!lst)
		return (NULL);
	newlist = (t_ftlist *)malloc(sizeof(t_ftlist));
	if (!newlist)
		return (NULL);
	ft_memcpy(newlist, f(lst), sizeof(t_ftlist));
	newlist->next = NULL;
	newlisthead = newlist;
	while (lst->next)
	{
		newlist->next = (t_ftlist *)malloc(sizeof(t_ftlist));
		if (!newlist->next)
			return (NULL);
		ft_memcpy(newlist->next, f(lst->next), sizeof(t_ftlist));
		newlist->next->next = NULL;
		newlist = newlist->next;
		lst = lst->next;
	}
	return (newlisthead);
}

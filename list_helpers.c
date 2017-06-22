/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmclaugh <pmclaugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 18:48:03 by pmclaugh          #+#    #+#             */
/*   Updated: 2017/04/21 21:04:54 by pmclaugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int		is_sorted(t_list *list)
{
	if (!list)
		return (1);
	while (list->next)
	{
		if (list->val < list->next->val)
			list = list->next;
		else
			return (0);
	}
	return (1);
}

void	free_list(t_list *list)
{
	t_list *l;

	while (list)
	{
		l = list->next;
		free(list);
		list = l;
	}
}

t_list	*dupe_list(t_list *list)
{
	t_list	*dupe;
	int		i;

	i = lstlen(list);
	dupe = NULL;
	while (i--)
		push(&dupe, new_node(lstat(list, i)->val));
	return (dupe);
}

void	print_list(t_list *list)
{
	if (list)
	{
		ft_printf("[ %d ] - ", list->val);
		print_list(list->next);
	}
	else
		ft_printf("[ N ]\n");
}

int		lstlen(t_list *begin_list)
{
	int i;

	i = 0;
	while (begin_list)
	{
		begin_list = begin_list->next;
		i++;
	}
	return (i);
}

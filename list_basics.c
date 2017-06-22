/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_basics.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmclaugh <pmclaugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 06:48:01 by pmclaugh          #+#    #+#             */
/*   Updated: 2017/04/21 19:27:49 by pmclaugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int		*list_to_arr(t_list *list, int *count)
{
	int *out;
	int i;

	out = (int *)ft_memalloc(sizeof(int) * lstlen(list));
	i = 0;
	while (list)
	{
		out[i] = list->val;
		i++;
		list = list->next;
	}
	if (count)
		*count = i;
	return (out);
}

t_list	*arr_to_list(int *arr, int count)
{
	t_list	*l;
	int		*head;

	l = NULL;
	head = arr;
	while (count--)
	{
		plug(&l, new_node(*arr));
		arr++;
	}
	free(head);
	return (l);
}

t_list	*new_node(int val)
{
	t_list *node;

	node = (t_list *)malloc(sizeof(t_list));
	node->val = val;
	node->next = NULL;
	return (node);
}

t_list	*lstat(t_list *begin_list, unsigned int i)
{
	while (i)
	{
		if (!begin_list)
			return (NULL);
		begin_list = begin_list->next;
		i--;
	}
	return (begin_list);
}

void	ft_listplug(t_ftlist **queue, t_ftlist *new)
{
	t_ftlist *seek;

	seek = *queue;
	if (new)
		new->next = NULL;
	else
		return ;
	if (!seek)
		*queue = new;
	else
	{
		while (seek->next)
			seek = seek->next;
		seek->next = new;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmclaugh <pmclaugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 18:41:29 by pmclaugh          #+#    #+#             */
/*   Updated: 2017/04/21 21:24:46 by pmclaugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int			good_move(t_list *in, enum e_instr i)
{
	if (tail(in)->val == opposite_instr(i))
		return (0);
	if (i == SA || i == RA || i == RRA)
		return (1);
	else
		return (0);
}

void		free_and_advance(t_ftlist **queue, t_list *b)
{
	t_ftlist *temp;

	free_list(*(t_list **)((*queue)->content));
	free_list(b);
	temp = *queue;
	*queue = temp->next;
	free(temp);
}

int			good_solution(t_list *a, t_list *in)
{
	t_list	*dupe;
	t_list	*b;

	dupe = dupe_list(a);
	b = NULL;
	follow_instructions_list(in, &dupe, &b);
	if (!b && is_sorted(dupe))
		return (1);
	else
		return (0);
}

void		populate_queue(t_ftlist **queue)
{
	t_list	*temp;

	*queue = NULL;
	temp = new_node(PA);
	ft_listplug(queue, ft_lstnew(&temp, sizeof(t_list **)));
	temp = new_node(RA);
	ft_listplug(queue, ft_lstnew(&temp, sizeof(t_list **)));
	temp = new_node(RRA);
	ft_listplug(queue, ft_lstnew(&temp, sizeof(t_list **)));
	temp = new_node(SA);
	ft_listplug(queue, ft_lstnew(&temp, sizeof(t_list **)));
}

t_list		*bfs_brute(t_list *a)
{
	t_ftlist	*queue;
	t_list		*temp;
	int			i;
	t_list		*b;

	b = NULL;
	populate_queue(&queue);
	while (queue)
	{
		i = -1;
		if (good_solution(a, *(t_list **)(queue->content)))
			return (*(t_list **)(queue->content));
		else
			while (++i < 8)
				if (good_move(*(t_list **)(queue->content), i))
				{
					temp = dupe_list(*(t_list **)(queue->content));
					plug(&temp, new_node(i));
					ft_listplug(&queue, ft_lstnew(&temp, sizeof(t_list **)));
				}
		free_and_advance(&queue, b);
	}
	return (NULL);
}

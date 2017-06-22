/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmclaugh <pmclaugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 19:54:58 by pmclaugh          #+#    #+#             */
/*   Updated: 2017/04/21 19:23:45 by pmclaugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void		condense(t_list *in)
{
	t_list	*temp;

	while (in && in->next && in->next->next)
	{
		if ((in->next->val == RA && in->next->next->val == RB) || \
			(in->next->val == RB && in->next->next->val == RA))
		{
			temp = in->next;
			in->next = in->next->next;
			free(temp);
			in->next->val = RR;
		}
		in = in->next;
	}
}

int			is_rotationally_sorted(t_list *list)
{
	int		count;
	t_list	*l;

	count = lstlen(list);
	l = dupe_list(list);
	while (count--)
	{
		if (is_sorted(l))
			return (1);
		rot_up(&l);
	}
	free_list(l);
	return (0);
}

void		free_split(char **split)
{
	if (!split)
		return ;
	while (*split)
		free(*split++);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dummies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmclaugh <pmclaugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 22:47:21 by pmclaugh          #+#    #+#             */
/*   Updated: 2017/04/21 20:04:36 by pmclaugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	make_dummies(t_list *stack)
{
	if (log2(lstlen(stack)) == floor(log2(lstlen(stack))))
		return ;
	while (log2(lstlen(stack)) != floor(log2(lstlen(stack))))
		plug(&stack, new_node(lstlen(stack)));
}

int		affects_dum(t_list **a, t_list **b, enum e_instr in, int max)
{
	if (in == PB || in == RA || in == SA)
		if (*a && (*a)->val >= max)
			return (1);
	if (in == PA || in == RB || in == SB)
		if (*b && (*b)->val >= max)
			return (1);
	if (in == SA)
		if (*a && (*a)->next && (*a)->next->val >= max)
			return (1);
	if ((in == SB && (*b)->next->val > max))
		if (*b && (*b)->next && (*b)->next->val >= max)
			return (1);
	return (0);
}

void	make_move_dum(t_list **a, t_list **b, t_list *in, int max)
{
	enum e_instr move;

	move = in->val;
	if (affects_dum(a, b, move, max))
		in->val = -1;
	if (move == PA)
		push(a, pop(b));
	if (move == PB)
		push(b, pop(a));
	if (move == SA || move == SS)
		swap(a);
	if (move == SB || move == SS)
		swap(b);
	if (move == RA || move == RR)
		rot_up(a);
	if (move == RB || move == RR)
		rot_up(b);
	if (move == RRA || move == RRR)
		rot_down(a);
	if (move == RRB || move == RRR)
		rot_down(b);
}

t_list	*remove_dummies(t_list *a, t_list *in)
{
	int		max;
	t_list	*b;
	t_list	*cleaned;

	max = lstlen(a);
	make_dummies(a);
	cleaned = in;
	b = NULL;
	while (in)
	{
		make_move_dum(&a, &b, in, max);
		in = in->next;
	}
	in = cleaned;
	b = in;
	cleaned = NULL;
	while (in)
	{
		if (in->val != -1)
			plug(&cleaned, new_node(in->val));
		in = in->next;
	}
	free_list(a);
	free_list(b);
	return (cleaned);
}

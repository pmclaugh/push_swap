/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmclaugh <pmclaugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 05:28:57 by pmclaugh          #+#    #+#             */
/*   Updated: 2017/04/21 20:02:39 by pmclaugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	make_move(t_list **a, t_list **b, t_list **in, enum e_instr instr)
{
	plug(in, new_node(instr));
	if (instr == PA)
		push(a, pop(b));
	if (instr == PB)
		push(b, pop(a));
	if (instr == SA || instr == SS)
		swap(a);
	if (instr == SB || instr == SS)
		swap(b);
	if (instr == RA || instr == RR)
		rot_up(a);
	if (instr == RB || instr == RR)
		rot_up(b);
	if (instr == RRA || instr == RRR)
		rot_down(a);
	if (instr == RRB || instr == RRR)
		rot_down(b);
}

void	swap(t_list **stack)
{
	t_list *a;
	t_list *b;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	a = *stack;
	b = a->next;
	a->next = b->next;
	b->next = a;
	*stack = b;
}

void	rot_up(t_list **stack)
{
	if (!stack || !*stack)
		return ;
	plug(stack, pop(stack));
}

void	rot_down(t_list **stack)
{
	if (!stack || !*stack)
		return ;
	push(stack, pluck(stack));
}

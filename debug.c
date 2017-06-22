/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmclaugh <pmclaugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 21:07:57 by pmclaugh          #+#    #+#             */
/*   Updated: 2017/04/21 21:20:18 by pmclaugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

char	*instr_to_str_nonl(enum e_instr in)
{
	char *step;

	if (in == PA)
		step = ft_strdup("pa");
	if (in == PB)
		step = ft_strdup("pb");
	if (in == SA)
		step = ft_strdup("sa");
	if (in == SB)
		step = ft_strdup("sb");
	if (in == SS)
		step = ft_strdup("ss");
	if (in == RA)
		step = ft_strdup("ra");
	if (in == RB)
		step = ft_strdup("rb");
	if (in == RR)
		step = ft_strdup("rr");
	if (in == RRA)
		step = ft_strdup("rra");
	if (in == RRB)
		step = ft_strdup("rrb");
	if (in == RRR)
		step = ft_strdup("rrr");
	return (step);
}

void	print_list_stderr(t_list *list)
{
	if (list)
	{
		fprintf(stderr, "[ %d ] - ", list->val);
		print_list_stderr(list->next);
	}
	else
		fprintf(stderr, "[ N ]\n");
}

void	print_instr_stderr(t_list *list)
{
	if (list)
	{
		fprintf(stderr, "[ %s ] - ", instr_to_str_nonl(list->val));
		print_instr_stderr(list->next);
	}
	else
		fprintf(stderr, "[ N ]\n");
}

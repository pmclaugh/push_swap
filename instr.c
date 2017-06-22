/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmclaugh <pmclaugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 19:21:01 by pmclaugh          #+#    #+#             */
/*   Updated: 2017/04/21 19:59:52 by pmclaugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

char			*instr_to_str(enum e_instr in)
{
	char *step;

	if (in == PA)
		step = ft_strdup("pa\n");
	if (in == PB)
		step = ft_strdup("pb\n");
	if (in == SA)
		step = ft_strdup("sa\n");
	if (in == SB)
		step = ft_strdup("sb\n");
	if (in == SS)
		step = ft_strdup("ss\n");
	if (in == RA)
		step = ft_strdup("ra\n");
	if (in == RB)
		step = ft_strdup("rb\n");
	if (in == RR)
		step = ft_strdup("rr\n");
	if (in == RRA)
		step = ft_strdup("rra\n");
	if (in == RRB)
		step = ft_strdup("rrb\n");
	if (in == RRR)
		step = ft_strdup("rrr\n");
	return (step);
}

enum e_instr	opposite_instr(enum e_instr in)
{
	if (in == SS || in == RR || in == RRR)
		return (in);
	if (in == PA)
		return (PB);
	if (in == PB)
		return (PA);
	if (in == RA)
		return (RRA);
	if (in == RB)
		return (RRB);
	if (in == RRA)
		return (RA);
	if (in == RRB)
		return (RB);
	if (in == SA)
		return (SA);
	else
		return (SB);
}

enum e_instr	mirr_instr(enum e_instr in, int flag)
{
	if (flag == 0)
		return (in);
	if (in == SS || in == RR || in == RRR)
		return (in);
	if (in == PA)
		return (PB);
	if (in == PB)
		return (PA);
	if (in == RA)
		return (RB);
	if (in == RB)
		return (RA);
	if (in == RRA)
		return (RRB);
	if (in == RRB)
		return (RRA);
	if (in == SA)
		return (SB);
	else
		return (SA);
}

void			instructions_to_stdout(t_list *in)
{
	char	*str;

	while (in)
	{
		str = instr_to_str(in->val);
		write(1, str, ft_strlen(str));
		in = in->next;
		free(str);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmclaugh <pmclaugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 18:15:48 by pmclaugh          #+#    #+#             */
/*   Updated: 2017/04/21 19:27:29 by pmclaugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void		add_vec(int *a, int *b, int count)
{
	while (count--)
		a[count] = a[count] + b[count];
	free(b);
}

void		do_in4(t_list **a, t_list **b, t_list **in)
{
	char	**patterns;
	int		count;
	int		*abcd;
	int		*ops;
	int		j;

	abcd = make_sequence(0, 1, 1, 4);
	count = lstlen(*a);
	patterns = load_file("patterns/IN4");
	while (count)
	{
		ops = make_instr_arr(recognize_4pat(patterns, \
			grab_next_n(*a, 4), abcd));
		j = 0;
		while (*ops != -1)
			make_move(a, b, in, *ops++);
		j = -1;
		while (++j < 4)
			abcd[j] = abcd[j] + 4;
		count -= 4;
	}
	free_split(patterns);
}

void		do_tr4(t_list **a, t_list **b, t_list **in)
{
	int curr;
	int j;

	curr = lstlen(*b) - 1;
	while (lstlen(*b) > lstlen(*a))
	{
		j = 0;
		while (j++ < 4)
			if ((*b)->val == curr || (*b)->val == curr - 1)
				make_move(a, b, in, PA);
			else
				make_move(a, b, in, RB);
		if (*a && (*a)->next && (*a)->val > (*a)->next->val)
			make_move(a, b, in, SA);
		curr -= 2;
	}
	while (lstlen(*b))
	{
		make_move(a, b, in, PA);
		make_move(a, b, in, PA);
		if (*a && (*a)->next && (*a)->val > (*a)->next->val)
			make_move(a, b, in, SA);
	}
}

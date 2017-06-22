/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmclaugh <pmclaugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 17:42:06 by pmclaugh          #+#    #+#             */
/*   Updated: 2017/04/21 22:21:53 by pmclaugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void		tuck(t_list **a, t_list **b, t_list **in, int rev)
{
	make_move(a, b, in, mirr_instr(PB, rev));
	make_move(a, b, in, mirr_instr(RB, rev));
}

void		do_map(t_list **a, t_list **b, t_list **in, int *map)
{
	t_list	**l;
	int		count;
	int		rev;

	rev = *a ? 0 : 1;
	l = rev ? b : a;
	count = lstlen(*l);
	while (count--)
		if (map[(*l)->val] == 0 || map[(*l)->val] == 3)
			make_move(a, b, in, mirr_instr(RA, rev));
		else if (map[(*l)->val] == 2)
			tuck(a, b, in, rev);
		else
			make_move(a, b, in, mirr_instr(PB, rev));
	count = lstlen(*l);
	while (count--)
		if (map[(*l)->val] == 3)
			tuck(a, b, in, rev);
		else
			make_move(a, b, in, mirr_instr(PB, rev));
}

t_kit		*new_kit(t_list **a, t_list **b, t_list **in, int *abcd)
{
	t_kit *kit;

	kit = (t_kit *)ft_memalloc(sizeof(t_kit));
	kit->a = a;
	kit->b = b;
	kit->in = in;
	kit->abcd = abcd;
	return (kit);
}

void		do_ops_kit(int *ops, t_kit *kit, int count, int rev)
{
	int		j;
	int		i;
	t_list	**l;

	i = 0;
	j = 0;
	l = rev ? kit->b : kit->a;
	while (ops[i] != -1 || (count == 8 && j < 4))
	{
		if ((*l)->val == kit->abcd[0] || (*l)->val == kit->abcd[1] || \
			(*l)->val == kit->abcd[2] || (*l)->val == kit->abcd[3])
		{
			make_move(kit->a, kit->b, kit->in, ops[i++]);
			while (ops[i] != mirr_instr(PB, rev) && ops[i] != -1)
				make_move(kit->a, kit->b, kit->in, ops[i++]);
		}
		else
		{
			make_move(kit->a, kit->b, kit->in, mirr_instr(RA, rev));
			j++;
		}
	}
	free(kit);
	free(ops);
}

void		do_tr8(t_list **a, t_list **b, t_list **in)
{
	char	**patterns;
	int		*abcd;
	t_kit	*k;

	abcd = make_sequence(lstlen(*b) / 2 - 2, 1, 1, 4);
	patterns = load_file("patterns/TR8");
	while (lstlen(*b) > lstlen(*a))
	{
		k = new_kit(a, b, in, abcd);
		do_ops_kit(make_instr_arr(recognize_8pat(patterns, \
			grab_next_n(*b, 8), abcd)), k, 8, 1);
		add_vec(abcd, make_sequence(-2, 4, 2, 4), 4);
	}
	while (lstlen(*b))
	{
		k = new_kit(a, b, in, abcd);
		do_ops_kit(make_instr_arr(recognize_4pat(patterns, \
			grab_next_n(*b, 4), abcd)), k, 4, 1);
		add_vec(abcd, make_sequence(-2, 4, 2, 4), 4);
	}
	free(abcd);
	free_split(patterns);
}

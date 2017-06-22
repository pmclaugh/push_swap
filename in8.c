/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in8.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmclaugh <pmclaugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 17:24:42 by pmclaugh          #+#    #+#             */
/*   Updated: 2017/04/21 18:13:23 by pmclaugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int			*make_sequence(int start, int diff, int width, int count)
{
	int *seq;
	int i;
	int j;

	seq = (int *)ft_memalloc(sizeof(int) * count);
	i = 0;
	while (i < count)
	{
		j = 0;
		while (j++ < width)
			seq[i++] = start;
		start += diff;
	}
	return (seq);
}

int			*in8map(int count)
{
	int *map;
	int *seq;

	map = (int *)ft_memalloc(sizeof(int) * count);
	seq = make_sequence(count / 8 - 1, -1, 2, count / 4);
	ft_memcpy(map, seq, sizeof(int) * count / 4);
	free(seq);
	seq = make_sequence(0, 1, 2, count / 4);
	ft_memcpy(map + (count / 4), seq, sizeof(int) * count / 4);
	free(seq);
	seq = make_sequence(0, 1, 4, count / 2);
	ft_memcpy(map + (count / 2), seq, sizeof(int) * count / 2);
	free(seq);
	return (map);
}

void		do_tr4_in8(t_list **a, t_list **b, t_list **in)
{
	char	**patterns;
	int		*abcd;
	t_kit	*k;

	patterns = load_file("patterns/IN8");
	abcd = make_sequence(lstlen(*a) / 4 + 1, -1, 1, 4);
	while (lstlen(*a) != lstlen(*b))
	{
		k = new_kit(a, b, in, abcd);
		do_ops_kit(make_instr_arr(recognize_8pat(patterns, \
			grab_next_n(*a, 8), abcd)), k, 8, 0);
		add_vec(abcd, make_sequence(2, -4, 2, 4), 4);
	}
	free(abcd);
	free_split(patterns);
}

void		do_in4_in8(t_list **a, t_list **b, t_list **in)
{
	char	**patterns;
	int		count;
	int		*abcd;
	int		*ops;
	int		j;

	patterns = load_file("patterns/IN4");
	count = lstlen(*a);
	abcd = make_sequence(count, 1, 1, 4);
	while (count)
	{
		ops = make_instr_arr(recognize_4pat(patterns, \
			grab_next_n(*a, 4), abcd));
		while (*ops != -1)
			make_move(a, b, in, *ops++);
		j = -1;
		while (++j < 4)
			abcd[j] = abcd[j] + 4;
		count -= 4;
	}
	free(abcd);
	free_split(patterns);
}

void		do_in8(t_list **a, t_list **b, t_list **in)
{
	do_tr4_in8(a, b, in);
	do_in4_in8(a, b, in);
	while (*b)
		make_move(a, b, in, PA);
}

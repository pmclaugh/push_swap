/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvemain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmclaugh <pmclaugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 19:55:03 by pmclaugh          #+#    #+#             */
/*   Updated: 2017/04/21 21:14:55 by pmclaugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

t_list	*topological_partition_sort(t_list *a, int **maps)
{
	t_list	*b;
	t_list	*in;
	int		count;
	int		i;

	b = NULL;
	in = NULL;
	i = count_maps(maps);
	count = lstlen(a);
	while (i--)
		do_map(&a, &b, &in, maps[i]);
	if (plan(count) == TR8)
		do_tr8(&a, &b, &in);
	else if (plan(count) == TR4)
		do_tr4(&a, &b, &in);
	else if (plan(count) == IN4)
		do_in4(&a, &b, &in);
	else if (plan(count) == IN8)
		do_in8(&a, &b, &in);
	return (in);
}

t_list	*tps_small(t_list *a)
{
	t_list	*b;
	t_list	*in;

	b = NULL;
	in = NULL;
	if (lstlen(a) > 5)
	{
		make_dummies(a);
		do_in8(&a, &b, &in);
		return (in);
	}
	else
		return (bfs_brute(a));
}

void	free_maps(int **maps)
{
	int i;

	i = 0;
	while (maps[i])
		free(maps[i++]);
	free(maps);
}

int		main(int ac, char **av)
{
	t_list	*a;
	t_list	*in;
	int		**maps;

	a = load(ac, av);
	if (is_sorted(a))
		return (0);
	if (lstlen(a) <= 8)
		in = tps_small(a);
	else
	{
		make_dummies(a);
		maps = paint(lstlen(a), (int)(log2(lstlen(a))) % 2 == 0 ? 4 : 8);
		in = topological_partition_sort(dupe_list(a), maps);
		free_maps(maps);
	}
	if (lstlen(a) >= 8)
	{
		in = remove_dummies(load(ac, av), in);
		condense(in);
	}
	instructions_to_stdout(in);
	free_list(a);
	free_list(in);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   demo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmclaugh <pmclaugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 21:17:24 by pmclaugh          #+#    #+#             */
/*   Updated: 2017/04/24 20:06:35 by pmclaugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ps.h"
#include <math.h>

int		**demo_paint(int count)
{
	int **maps;
	int i;
	int j;
	int divcount;

	maps = (int **)ft_memalloc(sizeof(int *) * (1 + log2(count) / 2));
	maps[(int)(log2(count) / 2)] = NULL;
	divcount = count;
	maps[0] = make_sequence(0, 1, 1, count);
	i = 1;
	while (i < log2(count) / 2)
	{
		j = 0;
		maps[i] = (int *)ft_memalloc(sizeof(int) * count);
		while (j < count)
		{
			maps[i][j] = map_val(maps[i - 1][j], divcount);
			j++;
		}
		i++;
		divcount /= 4;
	}
	return (maps);
}

void	demo_do_map(t_kit *k, int *map, int *map2)
{
	t_list	**l;
	int		count;
	int		rev;

	rev = *(k->a) ? 0 : 1;
	l = rev ? k->b : k->a;
	count = lstlen(*l);
	while (status_display(k, map, map2) && count--)
		if (map[(*l)->val] == 0 || map[(*l)->val] == 3)
			make_move(k->a, k->b, k->in, mirr_instr(RA, rev));
		else if (map[(*l)->val] == 2)
			tuck(k->a, k->b, k->in, rev);
		else
			make_move(k->a, k->b, k->in, mirr_instr(PB, rev));
	count = lstlen(*l);
	while (status_display(k, map, map2) && count--)
		if (map[(*l)->val] == 3)
			tuck(k->a, k->b, k->in, rev);
		else
			make_move(k->a, k->b, k->in, mirr_instr(PB, rev));
	free(k);
}

void	show_maps(t_list *l)
{
	int **maps;

	maps = demo_paint(lstlen(l));
	print_trimap(maps[0], maps[1], maps[2], lstlen(l));
	paint_flat(maps, lstlen(l), lstlen(l));
	print_trimap(maps[0], maps[1], maps[2], lstlen(l));
}

void	show_sort(t_list *l)
{
	int		**maps;
	int		**basemaps;
	int		i;
	t_list	*b;
	t_list	*in;

	b = NULL;
	in = NULL;
	maps = demo_paint(lstlen(l));
	paint_flat(maps, lstlen(l), lstlen(l));
	basemaps = demo_paint(lstlen(l));
	i = count_maps(maps);
	while (i--)
		demo_do_map(new_kit(&l, &b, &in, NULL), maps[i], basemaps[i]);
}

int		main(int ac, char **av)
{
	show_maps(load(ac, av));
	getchar();
	show_sort(load(ac, av));
	return (0);
}

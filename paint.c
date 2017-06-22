/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmclaugh <pmclaugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 02:50:33 by pmclaugh          #+#    #+#             */
/*   Updated: 2017/04/21 23:54:41 by pmclaugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int			**paint(int count, int end_section_size)
{
	int **maps;
	int i;
	int j;
	int divcount;

	maps = (int **)ft_memalloc(sizeof(int *) * (1 + log2(count) / 2));
	maps[(int)(log2(count) / 2)] = NULL;
	divcount = count / end_section_size;
	maps[0] = base_map(count, plan(count));
	i = 1;
	while (i < log2(count / end_section_size) / 2)
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
	paint_flat(maps, count / end_section_size, count);
	return (maps);
}

void		paint_flat(int **maps, int divcount, int count)
{
	int i;
	int j;
	int iter;

	iter = (int)(log2(divcount) / 2);
	i = 0;
	while (i < iter)
	{
		j = 0;
		while (j < count)
		{
			maps[i][j] = maps[i][j] / (divcount / 4);
			j++;
		}
		i++;
		divcount /= 4;
	}
}

void		paint_ordinals(int *arr, int len)
{
	int *ords;
	int i;
	int j;

	ords = (int *)malloc(sizeof(int) * len);
	ft_memcpy(ords, arr, sizeof(int) * len);
	heap_sort(ords, len);
	i = 0;
	while (i < len)
	{
		j = 0;
		while (arr[i] != ords[j])
			j++;
		arr[i] = j;
		i++;
	}
	free(ords);
}

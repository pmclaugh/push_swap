/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmclaugh <pmclaugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 19:16:40 by pmclaugh          #+#    #+#             */
/*   Updated: 2017/04/21 19:13:33 by pmclaugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ps.h"

int			map_val(int n, int count)
{
	if (n < count / 2)
		return (count / 4 - n % (count / 4) - 1);
	else
		return (n % (count / 4));
}

int			*in4map(int count)
{
	int i;
	int *map;

	i = 0;
	map = (int *)ft_memalloc(count * sizeof(int));
	while (i < count)
	{
		map[i] = i / 4;
		i++;
	}
	return (map);
}

int			*tr4map(int count)
{
	int *map;
	int i;
	int j;

	map = (int *)ft_memalloc(count * sizeof(int));
	i = 0;
	j = count / 4 - 1;
	while (i < count)
	{
		map[i] = j;
		map[i + 1] = j;
		i += 2;
		j--;
		if (j < 0)
			j = count / 4 - 1;
	}
	return (map);
}

int			*tr8map(int count)
{
	int *map;
	int i;
	int j;

	map = (int *)ft_memalloc(count * sizeof(int));
	i = 0;
	j = count / 8 - 1;
	while (i < count)
	{
		map[i] = j;
		map[i + 1] = j;
		i += 2;
		if (i < count / 2)
			j = j == 0 ? count / 8 - 1 : j - 1;
		if (i > count / 2)
			j = j == count / 8 - 1 ? 0 : j + 1;
	}
	return (map);
}

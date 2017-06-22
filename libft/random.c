/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmclaugh <pmclaugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 20:32:21 by pmclaugh          #+#    #+#             */
/*   Updated: 2017/04/21 21:23:14 by pmclaugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	rand_lcg(void)
{
	static int		*seed;
	unsigned long	a;
	unsigned long	c;

	a = 1664525;
	c = 1013904223;
	if (seed == NULL)
	{
		seed = (int *)malloc(sizeof(int));
		*seed = (int)seed;
	}
	*seed = (int)(a * (*seed) + c);
	return (*seed);
}

int			ft_rand(int max)
{
	return (rand_lcg() % max);
}

int			*random_sequence(int max)
{
	int *arr;
	int *ords;
	int i;
	int j;

	arr = (int *)ft_memalloc(sizeof(int) * max);
	ords = (int *)ft_memalloc(sizeof(int) * max);
	i = 0;
	while (i < max)
	{
		arr[i] = rand_lcg();
		i++;
	}
	ft_memcpy(ords, arr, sizeof(int) * max);
	heap_sort(ords, max);
	i = 0;
	while (i < max)
	{
		j = 0;
		while (ords[j] != arr[i])
			j++;
		arr[i] = j;
		i++;
	}
	return (arr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmclaugh <pmclaugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 02:51:30 by pmclaugh          #+#    #+#             */
/*   Updated: 2017/04/25 17:00:45 by pmclaugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"
#include <limits.h>

int		is_numbers(char *str)
{
	while (*str && ft_isdigit(*str))
		str++;
	return (*str ? 0 : 1);
}

int		check_errors(char **split)
{
	int i;

	i = 0;
	while (split[i])
	{
		if (!is_numbers(split[i]))
			return (0);
		if (ft_strlen(split[i]) > 10 || ft_atol(split[i]) > INT_MAX)
			return (0);
		i++;
	}
	return (1);
}

int		check_dupes(int *arr, int count)
{
	int i;
	int j;

	i = 0;
	while (i < count)
	{
		j = i;
		while (++j < count)
			if (arr[i] == arr[j])
				return (0);
		i++;
	}
	return (1);
}

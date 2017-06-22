/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pats.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmclaugh <pmclaugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 04:21:54 by pmclaugh          #+#    #+#             */
/*   Updated: 2017/04/21 19:14:42 by pmclaugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int		*grab_next_n(t_list *a, int n)
{
	int *arr;
	int i;

	arr = (int *)ft_memalloc(sizeof(int) * n);
	i = 0;
	while (i < n && a)
	{
		arr[i] = a->val;
		i++;
		a = a->next;
	}
	return (arr);
}

char	*recognize_8pat(char **patterns, int *eight, int abcd[4])
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = (char *)ft_memalloc(5);
	while (i < 8)
	{
		if (eight[i] == abcd[0])
			str[j++] = 'A';
		else if (eight[i] == abcd[1])
			str[j++] = 'B';
		else if (eight[i] == abcd[2])
			str[j++] = 'C';
		else if (eight[i] == abcd[3])
			str[j++] = 'D';
		i++;
	}
	str[4] = 0;
	free(eight);
	return (match(str, patterns));
}

char	*recognize_4pat(char **patterns, int *four, int abcd[4])
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)ft_memalloc(5);
	while (i < 4)
	{
		if (four[i] == abcd[0])
			str[i] = 'A';
		else if (four[i] == abcd[1])
			str[i] = 'B';
		else if (four[i] == abcd[2])
			str[i] = 'C';
		else if (four[i] == abcd[3])
			str[i] = 'D';
		i++;
	}
	free(four);
	return (match(str, patterns));
}

char	*match(char *str, char **split)
{
	int i;

	i = 0;
	while (split[i])
	{
		if (ft_strncmp(split[i], str, ft_strlen(str)) == 0)
		{
			free(str);
			return (ft_strsub(split[i], 5, ft_strlen(split[i]) - 5));
		}
		i++;
	}
	free(str);
	return (NULL);
}

int		*make_instr_arr(char *str)
{
	char	**split;
	int		*instr;
	int		i;

	split = ft_strsplit(str, ' ');
	instr = (int *)ft_memalloc(sizeof(int) * (splitlen(split) + 1));
	instr[splitlen(split)] = -1;
	i = 0;
	while (split[i])
	{
		instr[i] = str_to_instr(split[i]);
		i++;
	}
	free_split(split);
	free(str);
	return (instr);
}

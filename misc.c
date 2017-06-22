/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmclaugh <pmclaugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 17:35:56 by pmclaugh          #+#    #+#             */
/*   Updated: 2017/04/21 20:00:48 by pmclaugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

enum e_fintype	plan(int n)
{
	if ((int)log2(n) % 4 == 0)
		return (TR4);
	if ((int)log2(n) % 4 == 1)
		return (TR8);
	if ((int)log2(n) % 4 == 2)
		return (IN4);
	else
		return (IN8);
}

int				count_maps(int **maps)
{
	int i;

	i = 0;
	while (maps[i])
		i++;
	return (i);
}

int				splitlen(char **split)
{
	int i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

int				*base_map(int elemcount, enum e_fintype fin)
{
	if (fin == TR4)
		return (tr4map(elemcount));
	if (fin == TR8)
		return (tr8map(elemcount));
	if (fin == IN4)
		return (in4map(elemcount));
	else
		return (in8map(elemcount));
}

int				count_lines(char *file)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	while (get_next_line(fd, &line))
		i++;
	close(fd);
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmclaugh <pmclaugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 04:26:20 by pmclaugh          #+#    #+#             */
/*   Updated: 2017/04/25 16:56:18 by pmclaugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

t_list	*load(int ac, char **av)
{
	t_list *a;

	a = NULL;
	if (ac == 2)
		a = stack_from_string(av[1]);
	else if (ac == 3 && ft_strcmp(av[1], "-f") == 0)
		a = stack_from_file(av[2]);
	else if (ac > 2)
		a = stack_from_args(ac, av);
	if (ac == 1)
		exit(1);
	if (!a)
	{
		ft_putendl_fd("Error", 2);
		exit(1);
	}
	return (a);
}

char	**load_file(char *file)
{
	char	**out;
	char	*line;
	int		fd;
	int		i;

	i = count_lines(file);
	out = (char **)malloc(sizeof(char *) * (i + 1));
	out[i] = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	i = 0;
	while (get_next_line(fd, &line))
		out[i++] = line;
	close(fd);
	return (out);
}

t_list	*stack_from_args(int ac, char **av)
{
	int		i;
	int		*arr;

	arr = (int *)ft_memalloc(sizeof(int) * (ac - 1));
	i = 1;
	while (i < ac)
	{
		arr[i - 1] = ft_atoi(av[i]);
		i++;
	}
	if (!check_errors(av + 1) || !check_dupes(arr, ac - 1))
		return (NULL);
	paint_ordinals(arr, (ac - 1));
	return (arr_to_list(arr, (ac - 1)));
}

t_list	*stack_from_string(char *str)
{
	int		i;
	char	**split;
	int		*arr;
	int		len;

	i = -1;
	split = ft_strsplit(str, ' ');
	len = splitlen(split);
	arr = (int *)ft_memalloc(sizeof(int) * len);
	while (++i < len)
		arr[i] = ft_atoi(split[i]);
	if (!check_errors(split) || !check_dupes(arr, len))
		return (NULL);
	paint_ordinals(arr, len);
	free_split(split);
	return (arr_to_list(arr, len));
}

t_list	*stack_from_file(char *file)
{
	int		i;
	char	**split;
	int		*arr;
	int		len;

	i = -1;
	split = load_file(file);
	if (!split)
		return (NULL);
	len = splitlen(split);
	arr = (int *)ft_memalloc(sizeof(int) * len);
	while (++i < len)
		arr[i] = ft_atoi(split[i]);
	paint_ordinals(arr, len);
	free_split(split);
	return (arr_to_list(arr, len));
}

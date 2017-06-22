/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmclaugh <pmclaugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 21:17:27 by pmclaugh          #+#    #+#             */
/*   Updated: 2017/04/24 20:06:38 by pmclaugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ps.h"
#include <math.h>
#define RESET_ANSI   "\x1b[0m"
#define C_256 			"\x1b[38;5;%dm"
#define COLOR(X) ((X) == 15 ? 202 : (X) + 1)
#define MAX(X, Y) ((X) > (Y) ? X : Y)

void	print_label(int n)
{
	ft_printf(C_256 "%d " RESET_ANSI, COLOR(n), n);
}

int		status_display(t_kit *k, int *map, int *map2)
{
	static int	inst;
	int			j;

	ft_printf("\e[1;1H\e[2J");
	status_print(*(k->a), *(k->b), map, map2);
	j = lstlen(*(k->a)) > lstlen(*(k->b)) ? lstlen(*(k->a)) : lstlen(*(k->b));
	while (j++ < 64)
		ft_printf("\n");
	ft_printf("+%d, %d\n", lstlen(*(k->in)) - inst, lstlen(*(k->in)));
	inst = lstlen(*(k->in));
	getchar();
	return (1);
}

void	print_trimap(int *map, int *map2, int *map3, int count)
{
	int i;
	int j;

	ft_printf("----------------------\n");
	i = 0;
	while (i < count)
	{
		j = -1;
		while (++j < MAX(exp2((int)((log2(count) - 1) / 2)), 4))
			ft_printf(C_256 "[%-3d]-" RESET_ANSI, COLOR(map[i + j]), i + j);
		ft_printf("     ");
		j = -1;
		while (++j < MAX(exp2((int)((log2(count) - 1) / 2)), 4))
			ft_printf(C_256 "[%-3d]-" RESET_ANSI, COLOR(map2[i + j]), i + j);
		ft_printf("     ");
		j = -1;
		while (++j < MAX(exp2((int)((log2(count) - 1) / 2)), 4))
			ft_printf(C_256 "[%-3d]-" RESET_ANSI, COLOR(map3[i + j]), i + j);
		ft_printf("\n");
		i += MAX(exp2((int)((log2(count) - 1) / 2)), 4);
	}
}

void	print_list_trimap(int *map1, int *map2, int *map3, t_list *l)
{
	int		count;
	t_list	*head;
	int		j;

	ft_printf("----------------------\n");
	count = lstlen(l);
	while (l)
	{
		head = l;
		j = MAX(exp2(log2(count) / 2), 4);
		while ((l = l->next) && j--)
			ft_printf(C_256 "[%-3d]-" RESET_ANSI, COLOR(map1[l->val]), l->val);
		ft_printf("     ");
		j = MAX(exp2(log2(count) / 2), 4);
		l = head;
		while ((l = l->next) && j--)
			ft_printf(C_256 "[%-3d]-" RESET_ANSI, COLOR(map2[l->val]), l->val);
		ft_printf("     ");
		j = MAX(exp2(log2(count) / 2), 4);
		l = head;
		while ((l = l->next) && j--)
			ft_printf(C_256 "[%-3d]-" RESET_ANSI, COLOR(map3[l->val]), l->val);
		ft_printf("\n");
	}
}

void	status_print(t_list *a, t_list *b, int *map, int *map2)
{
	int i;

	i = 0;
	ft_printf("----------------------\n");
	while ((a || b) && i++ < 64)
	{
		if (a)
		{
			ft_printf(C_256 "*" RESET_ANSI, COLOR(map[a->val]));
			ft_printf(C_256 "[%2d]" RESET_ANSI, COLOR(map2[a->val]), a->val);
			a = a->next;
		}
		if (b)
		{
			ft_printf("\t\t\t\t");
			ft_printf(C_256 "*" RESET_ANSI, COLOR(map[b->val]));
			ft_printf(C_256 "[%2d]" RESET_ANSI, COLOR(map2[b->val]), b->val);
			b = b->next;
		}
		ft_printf("\n");
	}
}

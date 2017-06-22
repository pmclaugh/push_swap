/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmclaugh <pmclaugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 06:47:53 by pmclaugh          #+#    #+#             */
/*   Updated: 2017/04/25 16:58:31 by pmclaugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void			follow_instructions_list(t_list *in, t_list **a, t_list **b)
{
	while (in)
	{
		if (in->val == PA)
			push(a, pop(b));
		if (in->val == PB)
			push(b, pop(a));
		if (in->val == SA || in->val == SS)
			swap(a);
		if (in->val == SB || in->val == SS)
			swap(b);
		if (in->val == RA || in->val == RR)
			rot_up(a);
		if (in->val == RB || in->val == RR)
			rot_up(b);
		if (in->val == RRA || in->val == RRR)
			rot_down(a);
		if (in->val == RRB || in->val == RRR)
			rot_down(b);
		in = in->next;
	}
}

enum e_instr	str_to_instr(char *str)
{
	if (ft_strcmp(str, "sa") == 0)
		return (SA);
	if (ft_strcmp(str, "sb") == 0)
		return (SB);
	if (ft_strcmp(str, "ss") == 0)
		return (SS);
	if (ft_strcmp(str, "pa") == 0)
		return (PA);
	if (ft_strcmp(str, "pb") == 0)
		return (PB);
	if (ft_strcmp(str, "ra") == 0)
		return (RA);
	if (ft_strcmp(str, "rb") == 0)
		return (RB);
	if (ft_strcmp(str, "rr") == 0)
		return (RR);
	if (ft_strcmp(str, "rra") == 0)
		return (RRA);
	if (ft_strcmp(str, "rrb") == 0)
		return (RRB);
	if (ft_strcmp(str, "rrr") == 0)
		return (RRR);
	else
		return (-1);
}

void			quit_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

void			check_stdin(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	t_list	*in;
	char	*str;
	int		i;

	a = load(ac, av);
	b = NULL;
	in = NULL;
	while (get_next_line(0, &str))
	{
		i = str_to_instr(str);
		if (i != -1)
			plug(&in, new_node(str_to_instr(str)));
		else
			quit_error();
	}
	follow_instructions_list(in, &a, &b);
	if (is_sorted(a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_list(a);
	free_list(in);
}

void			check_file(t_list *in, char *nums_file)
{
	t_list *nums;
	t_list *b;

	b = NULL;
	nums = stack_from_file(nums_file);
	follow_instructions_list(in, &nums, &b);
	if (is_sorted(nums))
		ft_printf("solved in %d operations!\n", lstlen(in));
	else
		ft_printf("KO\n");
	free_list(nums);
	free_list(in);
}

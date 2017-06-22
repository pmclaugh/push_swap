/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmclaugh <pmclaugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 05:32:16 by pmclaugh          #+#    #+#             */
/*   Updated: 2017/04/18 18:52:30 by pmclaugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	push(t_list **stack, t_list *node)
{
	if (!node)
		return ;
	node->next = *stack;
	*stack = node;
}

t_list	*pop(t_list **stack)
{
	t_list *ret;

	ret = *stack;
	if (ret)
	{
		*stack = ret->next;
		ret->next = NULL;
	}
	return (ret);
}

void	plug(t_list **stack, t_list *node)
{
	t_list *tail;

	if (!node)
		return ;
	node->next = NULL;
	if (!stack)
		return ;
	tail = *stack;
	if (!tail)
	{
		*stack = node;
		return ;
	}
	while (tail->next)
		tail = tail->next;
	tail->next = node;
}

t_list	*pluck(t_list **stack)
{
	t_list *tail;
	t_list *temp;

	if (!stack || !*stack)
		return (NULL);
	tail = *stack;
	if (!(*stack)->next)
	{
		*stack = NULL;
		return (tail);
	}
	while (tail->next->next)
		tail = tail->next;
	temp = tail->next;
	tail->next = NULL;
	return (temp);
}

t_list	*tail(t_list *head)
{
	while (head && head->next)
		head = head->next;
	return (head);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etamazya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:57:13 by etamazya          #+#    #+#             */
/*   Updated: 2024/06/27 17:23:55 by etamazya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	set_index(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*curr;

	tmp = *stack;
	while (tmp)
	{
		tmp->index = 0;
		tmp = tmp->next;
	}
	curr = *stack;
	while (curr)
	{
		tmp = *stack;
		while (tmp)
		{
			if (curr->nbr > tmp->nbr)
				curr->index += 1;
			tmp = tmp->next;
		}
		curr = curr->next;
	}
}

int	get_position(t_stack_node **a, int res)
{
	int				pos;
	t_stack_node	*head;

	pos = 0;
	head = *a;
	while (head)
	{
		if (head->index == res)
			return (pos);
		pos++;
		head = head->next;
	}
	return (-1);
}

void	get_max_position(t_stack_node **a, long long *res)
{
	t_stack_node	*head;

	head = *a;
	*res = (*a)->nbr;
	while (head)
	{
		if (head->nbr > *res)
			*res = head->index;
		head = head->next;
	}
}

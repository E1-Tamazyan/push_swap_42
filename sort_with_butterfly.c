/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_with_butterfly.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etamazya <etamazya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:13:09 by etamazya          #+#    #+#             */
/*   Updated: 2024/07/16 16:57:25 by etamazya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_set(int size)
{
	int	i;
	int	a;
	int	b;

	i = 1;
	while (i * i <= size)
	{
		if (i * i * i <= size)
			a = i;
		if (i * i <= size)
			b = i;
		i++;
	}
	return (a + b + 1);
}

void	sort_b(t_stack_node **stack_a, t_stack_node **stack_b, int len)
{
	while (*stack_b)
	{
		if ((*stack_b)->index == len - 1)
		{
			len--;
			pa(stack_a, stack_b, 1);
		}
		else if (get_position(stack_b, len - 1) >= len / 2 + 1)
			rrb(stack_b, 1);
		else if (get_position(stack_b, len - 1) < len / 2 + 1)
			rb(stack_b, 1);
	}
}

void	sort_stack(t_stack_node **stack_a, t_stack_node **stack_b, int offset)
{
	int	n;

	n = 0;
	while (*stack_a != NULL)
	{
		if ((*stack_a)->index <= n)
		{
			pb(stack_a, stack_b, 1);
			rb(stack_b, 1);
			n++;
		}
		else if ((*stack_a)->index <= n + offset)
		{
			pb(stack_a, stack_b, 1);
			n++;
		}
		else
			ra(stack_a, 1);
	}
}

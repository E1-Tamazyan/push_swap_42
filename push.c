/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etamazya <etamazya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:44:07 by etamazya          #+#    #+#             */
/*   Updated: 2024/07/19 13:45:00 by etamazya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack_node **stack_to, t_stack_node **stack_from)
{
	t_stack_node	*temp;

	if (!stack_from || !stack_to || !(*stack_from))
		return ;
	temp = *stack_from;
	*stack_from = (*stack_from)->next;
	temp->next = *stack_to;
	*stack_to = temp;
	return ;
}

int	pa(t_stack_node **stack_a, t_stack_node **stack_b, int i)
{
	if (check_stack(*stack_b) == 1)
		return (1);
	push(stack_a, stack_b);
	if (i == 1)
		write(1, "pa\n", 3);
	return (1);
}

int	pb(t_stack_node **stack_a, t_stack_node **stack_b, int i)
{
	if (check_stack(*stack_a) == 1)
		return (1);
	push(stack_b, stack_a);
	if (i == 1)
		write(1, "pb\n", 3);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etamazya <etamazya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:49:35 by etamazya          #+#    #+#             */
/*   Updated: 2024/07/18 19:05:14 by etamazya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack_node **stack)
{
	t_stack_node	*head;
	t_stack_node	*tail;

	if (ft_lstsize(*stack) < 2)
		return ;
	head = *stack;
	tail = ft_lstlast(head);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
	return ;
}

int	ra(t_stack_node **stack_a, int i)
{
	if (check_stack(*stack_a) == 1)
		return (0);
	rotate(stack_a);
	if (i == 1)
		write(1, "ra\n", 3);
	return (1);
}

int	rb(t_stack_node **stack_b, int i)
{
	if (check_stack(*stack_b) == 1)
		return (0);
	rotate(stack_b);
	if (i == 1)
		write(1, "rb\n", 3);
	return (1);
}

int	rr(t_stack_node **stack_a, t_stack_node **stack_b, int i)
{
	if (check_stack(*stack_a) == 1 || check_stack(*stack_b) == 1)
		return (0);
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return (1);
	rotate(stack_a);
	rotate(stack_b);
	if (i == 1)
		write(1, "rr\n", 3);
	return (1);
}

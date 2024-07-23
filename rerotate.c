/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rerotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etamazya <etamazya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:47:07 by etamazya          #+#    #+#             */
/*   Updated: 2024/07/18 19:18:06 by etamazya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rerotate(t_stack_node **stack)
{
	t_stack_node	*head;
	t_stack_node	*tail;

	if (ft_lstsize(*stack) < 2)
		return ;
	head = *stack;
	tail = ft_lstlast(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	tail->next = *stack;
	*stack = tail;
	return ;
}

int	rra(t_stack_node **stack_a, int i)
{
	if (check_stack(*stack_a) == 1)
		return (0);
	rerotate(stack_a);
	if (i == 1)
		write(1, "rra\n", 4);
	return (1);
}

int	rrb(t_stack_node **stack_b, int i)
{
	if (check_stack(*stack_b) == 1)
		return (0);
	rerotate(stack_b);
	if (i == 1)
		write(1, "rrb\n", 4);
	return (1);
}

int	rrr(t_stack_node **stack_a, t_stack_node **stack_b, int i)
{
	if (check_stack(*stack_a) == 1 || check_stack(*stack_b) == 1)
		return (0);
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return (1);
	rerotate(stack_a);
	rerotate(stack_b);
	if (i == 1)
		write(1, "rrr\n", 4);
	return (1);
}

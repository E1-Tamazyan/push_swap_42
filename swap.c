/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etamazya <etamazya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:51:04 by etamazya          #+#    #+#             */
/*   Updated: 2024/07/19 10:38:41 by etamazya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack_node **stack)
{
	int	temp;

	if (!stack || !(*stack)->next)
		return ;
	temp = (*stack)->nbr;
	(*stack)->nbr = (*stack)->next->nbr;
	(*stack)->next->nbr = temp;
}

int	sa(t_stack_node **stack_a, int i)
{
	if (check_stack(*stack_a) == 1)
		return (0);
	if ((ft_lstsize(*stack_a) < 2))
		return (0);
	swap(stack_a);
	if (i == 1)
		write(1, "sa\n", 3);
	return (1);
}

int	sb(t_stack_node **stack_b, int i)
{
	if (check_stack(*stack_b) == 1)
		return (0);
	swap(stack_b);
	if (i == 1)
		write(1, "sb\n", 3);
	return (1);
}

int	ss(t_stack_node **stack_a, t_stack_node **stack_b, int i)
{
	if (check_stack(*stack_a) == 1 || check_stack(*stack_b) == 1)
		return (0);
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return (1);
	swap(stack_a);
	swap(stack_b);
	if (i == 1)
		write(1, "ss\n", 3);
	return (1);
}

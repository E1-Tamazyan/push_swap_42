/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etamazya <etamazya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:11:49 by etamazya          #+#    #+#             */
/*   Updated: 2024/07/19 14:15:48 by etamazya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_neccessary_sort(t_stack_node **a, t_stack_node **b)
{
	long long	nc;

	nc = 0;
	nc = ft_lstsize(*a);
	set_index(a);
	if (nc <= 5)
		simple_sort(a, b);
	else
	{
		sort_stack(a, b, get_set(nc));
		sort_b(a, b, nc);
	}
}

void	sort_a3(t_stack_node **a, int len_b)
{
	if ((*a)-> index == len_b + 2)
	{
		ra(a, 1);
		if ((*a)-> index > (*a)-> next -> index)
			sa(a, 1);
	}
	else if ((*a)-> index == len_b
		&& (*a)-> next -> index > (*a)-> next -> next -> index)
	{
		rra(a, 1);
		sa(a, 1);
	}
	else if ((*a)-> index == len_b + 1)
	{
		if ((*a)-> next -> index > (*a)-> next -> next -> index)
			rra(a, 1);
		else
			sa(a, 1);
	}
}

void	sort_b3(t_stack_node **b)
{
	if ((*b)-> index == 1)
	{
		if ((*b)-> next -> index > (*b)-> next -> next -> index)
			sb(b, 1);
		else
			rrb(b, 1);
	}
	else if ((*b)-> index == 2
		&& (*b)-> next -> index < (*b)-> next -> next -> index)
	{
		rrb(b, 1);
		if ((*b)-> index < (*b)-> next -> index)
			sb(b, 1);
	}
	else if ((*b)-> index == 0)
	{
		rb(b, 1);
		if ((*b)-> index < (*b)-> next -> index)
			sb(b, 1);
	}
}

int	min_in_a(t_stack_node *a, int len)
{
	while (a)
	{
		if (a -> index < len - 3)
			return (1);
		a = a -> next;
	}
	return (0);
}

void	simple_sort(t_stack_node **a, t_stack_node **b)
{
	int	len;

	len = ft_lstsize(*a);
	while (ft_lstsize(*a) > 3 || min_in_a(*a, len))
	{
		if ((*a)-> index >= len / 2)
			ra(a, 1);
		else
			pb(a, b, 1);
	}
	if (ft_lstsize(*a) == 2 && (*a)-> index > (*a)-> next -> index)
		sa(a, 1);
	if (ft_lstsize(*a) == 3)
		sort_a3(a, ft_lstsize(*b));
	if (ft_lstsize(*b) == 2 && (*b)-> index < (*b)-> next -> index)
		sb(b, 1);
	else if (ft_lstsize(*b) == 3)
		sort_b3(b);
	while ((*b))
		pa(a, b, 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etamazya <etamazya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:53:18 by etamazya          #+#    #+#             */
/*   Updated: 2024/07/16 20:53:21 by etamazya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_dup(t_stack_node *lst)
{
	t_stack_node	*temp;

	while (lst)
	{
		temp = lst -> next;
		while (temp)
		{
			if (temp->nbr == lst->nbr || temp->nbr < -2147483648
				|| temp->nbr > 2147483647)
				return (1);
			temp = temp->next;
		}
		lst = lst->next;
	}
	return (0);
}

int	is_ascending(t_stack_node *lst)
{
	int	min;

	if (!lst)
		return (0);
	min = lst -> nbr;
	lst = lst -> next;
	while (lst)
	{
		if (lst -> nbr <= min)
			return (0);
		min = lst -> nbr;
		lst = lst -> next;
	}
	return (1);
}

int	check_list(t_stack_node **lst)
{
	if (!lst || !*lst)
		return (0);
	if (is_dup(*lst))
		return (0);
	return (1);
}

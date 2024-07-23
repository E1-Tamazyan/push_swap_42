/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etamazya <etamazya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:58:16 by etamazya          #+#    #+#             */
/*   Updated: 2024/07/17 17:26:05 by etamazya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*ft_lstnew(long long num)
{
	t_stack_node	*node;

	node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!node)
		return (NULL);
	node->nbr = num;
	node->next = NULL;
	return (node);
}

t_stack_node	*new_empty_list(void)
{
	t_stack_node	*node;

	node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!node)
		return (NULL);
	node->next = NULL;
	return (node);
}

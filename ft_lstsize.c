/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etamazya <etamazya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:50:57 by etamazya          #+#    #+#             */
/*   Updated: 2024/07/16 21:01:26 by etamazya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_lstsize(t_stack_node *lst)
{
	long long		i;
	t_stack_node	*temp;

	temp = lst;
	i = 0;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

void	ft_lstiter(t_stack_node *lst)
{
	if (!lst)
		return ;
	while (lst)
	{
		lst = lst->next;
	}
}

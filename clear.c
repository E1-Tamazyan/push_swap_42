/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etamazya <etamazya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:27:42 by etamazya          #+#    #+#             */
/*   Updated: 2024/07/18 19:18:38 by etamazya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_stack(t_stack_node *lst)
{
	t_stack_node	*current;
	t_stack_node	*next;

	current = lst;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	lst = NULL;
}

void	clear_str(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free (arr);
}

void	ft_lstclear(t_stack_node **lst)
{
	t_stack_node	*next;

	if (!lst || !(*lst))
		return ;
	while (*lst)
	{
		next = (*lst)->next;
		free(*lst);
		*lst = next;
	}
	*lst = NULL;
}

int	check_stack(t_stack_node *stack)
{
	if (stack == NULL)
		return (1);
	return (0);
}

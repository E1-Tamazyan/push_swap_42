/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etamazya <etamazya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:50:44 by etamazya          #+#    #+#             */
/*   Updated: 2024/07/18 16:56:10 by etamazya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_r(t_stack_node **a, t_stack_node **b, char *line)
{
	if (line[1] == 'a' && line[2] == '\n')
		return (ra(a, 0));
	else if (line[1] == 'b' && line[2] == '\n')
		return (rb(b, 0));
	else if (line[1] == 'r' && line[2] == '\n')
		return (rr(a, b, 0));
	else if (line[1] == 'r' && line[2] == 'a' && line[3] == '\n')
		return (rra(a, 0));
	else if (line[1] == 'r' && line[2] == 'b' && line[3] == '\n')
		return (rrb(b, 0));
	else if (line[1] == 'r' && line[2] == 'r' && line[3] == '\n')
		return (rrr(a, b, 0));
	else
		return (0);
	return (1);
}

int	do_push(t_stack_node **a, t_stack_node **b, char *line)
{
	if (line[1] == 'a' && line[2] == '\n')
		return (pa(a, b, 0));
	else if (line[1] == 'b' && line[2] == '\n')
		return (pb(a, b, 0));
	else
		return (0);
	return (1);
}

int	do_swap(t_stack_node **a, t_stack_node **b, char *line)
{
	if (line[1] == 'a' && line[2] == '\n')
		return (sa(a, 0));
	if (line[1] == 'b' && line[2] == '\n')
		return (sb(b, 0));
	if (line[1] == 's' && line[2] == '\n')
		return (ss(a, b, 0));
	else
		return (0);
	return (1);
}

int	do_sort(t_stack_node **a, t_stack_node **b)
{
	char	*line;
	int		step;

	line = get_next_line(0);
	while (line)
	{
		if (line[0] == '\n' && line[1] == '\0')
			return (1);
		else if (line[0] == 'r')
			step = check_r(a, b, line);
		else if (line[0] == 'p')
			step = do_push(a, b, line);
		else if (line[0] == 's')
			step = do_swap(a, b, line);
		else
			step = 0;
		free (line);
		if (step == 0)
			return (0);
		line = get_next_line(0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack_node		*stack_a;
	t_stack_node		*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	if ((argc < 2 && !argv[1][0]) ||
			convert_verified(&stack_a, argv) == 0)
		exit(write(2, "Error\n", 6));
	else
	{
		if (do_sort(&stack_a, &stack_b) == 0)
		{
			ft_lstclear(&stack_a);
			return (!write(2, "Error\n", 6));
		}
		if (is_ascending(stack_a) == 1 && stack_b == NULL)
			ft_putstr_fd("OK\n", 1);
		else
			ft_putstr_fd("KO\n", 1);
		if (stack_b)
			ft_lstclear(&stack_b);
		ft_lstclear(&stack_a);
	}
}

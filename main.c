/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etamazya <etamazya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 15:07:36 by etamazya          #+#    #+#             */
/*   Updated: 2024/07/19 11:02:53 by etamazya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	else if (argc > 1)
	{
		if ((argc == 2 && (!argv[1][0])) || convert_verified(&a, argv) == 0)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		else
		{
			if (!is_ascending(a))
				find_neccessary_sort(&a, &b);
		}
	}
	return (0);
}

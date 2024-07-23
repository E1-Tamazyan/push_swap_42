/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifier.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etamazya <etamazya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:56:33 by etamazya          #+#    #+#             */
/*   Updated: 2024/07/19 11:03:45 by etamazya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tiny_verif(char *s)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (!s)
		exit(1 && write(2, "Error\n", 6));
	while (s[i] == '0')
		i++;
	while (s[i])
	{
		len++;
		i++;
	}
	if (len > 11)
		exit(1 && write(2, "Error\n", 6));
}

int	is_verified(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] && ((str[i] == '-' || str[i] == '+')
				&& !(str[i + 1] >= '0' && str[i + 1] <= '9')))
			return (0);
		else if (str[i] && (str[i] == ' '
				|| (str[i] && str[i] >= 9 && str[i] <= 13)))
			i++;
		else if (str[i] && (str[i] >= '0' && str[i] <= '9'))
			i++;
		else if ((str[i] >= 32 && str[i] <= 126)
			&& !(str[i] >= '0' && str[i] <= '9')
			&& str[i] != '-' && str[i] != '+')
			return (0);
		else
			i++;
	}
	if (!str[i])
		return (1);
	return (0);
}

void	init_stack_a(t_stack_node **stack_a, char **argv)
{
	int		i;
	int		j;
	char	**str;

	i = 1;
	str = NULL;
	while (argv[i])
	{
		str = ft_split(argv[i]);
		if (!str)
			return ;
		j = 0;
		tiny_verif(*str);
		while (str[j])
		{
			ft_lstadd_back(stack_a, ft_lstnew(ft_atoi(str[j])));
			j++;
		}
		i++;
		clear_str(str);
	}
	i = 0;
	if (!str)
		return ;
}

int	convert_verified(t_stack_node **stack_a, char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!is_verified(argv[i]))
			return (0);
		i++;
	}
	init_stack_a(stack_a, argv);
	if (!stack_a || !*stack_a)
		return (0);
	if (*stack_a)
	{
		if (!check_list(stack_a))
			return (0);
	}
	else
		return (0);
	return (1);
}

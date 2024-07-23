/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etamazya <etamazya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 11:13:00 by etamazya          #+#    #+#             */
/*   Updated: 2024/07/17 11:15:57 by etamazya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atoi(const char *str)
{
	long long	num;
	int			sign;
	int			i;

	num = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && str[i] == '0' && str[i + 1])
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + str[i] - '0';
		i++;
	}
	if (str[i] || sign * num > 2147483647 || sign * num < -2147483648)
		exit(write(2, "Error\n", 6));
	return (sign * num);
}

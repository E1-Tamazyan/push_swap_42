/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etamazya <etamazya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:09:03 by etamazya          #+#    #+#             */
/*   Updated: 2024/07/16 21:03:10 by etamazya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(const char *src)
{
	int	i;

	i = 0;
	if (!src)
		return (0);
	if (!*src)
		return (0);
	while (src[i])
		i++;
	return (i);
}

int	ft_dbstrlen( char **str)
{
	int	i;

	i = 0;
	if (!str || !str[i])
		return (0);
	while (str && str[i])
		i++;
	return (i);
}

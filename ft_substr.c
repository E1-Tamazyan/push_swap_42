/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etamazya <etamazya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 20:28:03 by etamazya          #+#    #+#             */
/*   Updated: 2024/07/16 18:32:55 by etamazya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_substr(char const *s, int start, int len)
{
	char	*sub;
	int		i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	if (len > ft_strlen(s))
		sub = (char *)malloc(ft_strlen(s));
	else
		sub = (char *)malloc(len + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len && s[start] != '\0')
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[i] = '\0';
	return (sub);
}

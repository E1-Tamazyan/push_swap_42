/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etamazya <etamazya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:58:06 by etamazya          #+#    #+#             */
/*   Updated: 2024/07/17 11:17:01 by etamazya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sep(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

static size_t	count_tokens(char const *str)
{
	size_t	tokens;
	int		inside_token;

	tokens = 0;
	while (*str)
	{
		inside_token = 0;
		while (*str && is_sep(*str))
			++str;
		while (*str && !is_sep(*str))
		{
			if (!inside_token)
			{
				tokens++;
				inside_token = 1;
			}
			++str;
		}
	}
	return (tokens);
}

char	**ft_split(char const *str)
{
	const char	*dup_str;
	char		**arr;
	int			wc;
	int			i;

	if (!str)
		return (NULL);
	wc = count_tokens(str);
	arr = (char **)malloc((wc + 1) * (sizeof(char *)));
	if (!arr)
		return (NULL);
	i = -1;
	while (++i < wc)
	{
		while (is_sep(*str))
			str++;
		dup_str = str;
		while (*str && !is_sep(*str))
			str++;
		arr[i] = ft_substr(dup_str, 0, str - dup_str);
		if (!arr[i] && ft_split(*arr))
			return (NULL);
	}
	arr[i] = NULL;
	return (arr);
}

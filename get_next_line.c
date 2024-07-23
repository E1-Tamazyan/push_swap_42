/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etamazya <etamazya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:08:33 by etamazya          #+#    #+#             */
/*   Updated: 2024/07/19 13:26:31 by etamazya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*read_str(int fd, char *s)
{
	char	*buf;
	int		n;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (1)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n == -1)
		{
			free(buf);
			return (0);
		}
		buf[n] = '\0';
		if (n == 0)
			break ;
		s = ft_strjoin(s, buf);
		if (ft_strchr(s, '\n'))
			break ;
	}
	free(buf);
	return (s);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str[OPEN_MAX];

	line = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (0);
	str[fd] = read_str(fd, str[fd]);
	if (!str[fd])
		return (0);
	line = ft_find(str[fd]);
	str[fd] = ft_remainder(str[fd]);
	if (line && !line[0])
	{
		free(line);
		return (0);
	}
	return (line);
}

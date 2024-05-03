/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeminian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 12:26:55 by aeminian          #+#    #+#             */
/*   Updated: 2024/03/06 17:54:44 by aeminian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	new_line_len(char *line)
{
	int	i;

	i = 0;
	if (!line || !*line)
		return (0);
	while (line[i])
	{
		if (line[i] == '\n')
		{
			i++;
			return (i);
		}
		i++;
	}
	return (i);
}

char	*strjoin(char *s1, char *s2)
{
	char	*memory;
	char	*result;
	size_t	size;

	if (!s1 && !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	memory = (char *)malloc(size +1);
	if (!memory)
		return (NULL);
	*(memory + size) = 0;
	result = memory;
	while (s1 && *s1)
		*memory++ = *s1++;
	while (*s2)
		*memory++ = *s2++;
	return (result);
}

int	found_new_line(char *line)
{
	if (!line || !*line)
		return (0);
	while (*line != 0 && *line != '\n')
		line++;
	if (*line == '\n')
		return (1);
	else
		return (0);
}

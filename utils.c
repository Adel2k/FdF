/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeminian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 19:15:00 by aeminian          #+#    #+#             */
/*   Updated: 2024/04/27 19:19:25 by aeminian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	malloc_check(void *str)
{
	if (!str)
		error_handle("Couldn't allocate memory!\n");
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	count_width(char **args)
{
	int	i;

	i = 0;
	while (!*args)
		return (0);
	while (args[i])
		i++;
	return (i);
}

void	error_handle(char *msg)
{
	int	len;

	len = ft_strlen(msg);
	write(2, msg, len);
	exit(EXIT_FAILURE);
}

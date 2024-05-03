/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeminian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 12:50:13 by aeminian          #+#    #+#             */
/*   Updated: 2024/04/29 21:56:09 by aeminian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*ptr;

	if (!s)
		return (NULL);
	else if ((start >= ft_strlen(s)))
		len = 0;
	else if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	s += start;
	ptr = str;
	*(str + len) = '\0';
	while (len-- && *s)
		*str++ = *s++;
	return (ptr);
}

static size_t	word_count(const char *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != 32 && !(s[i] >= 9 && s[i] <= 13) && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != 32 && \
			!(s[i] >= 9 && s[i] <= 13) && s[i] != c)
			{
				i++;
				if (s[i] == 0)
					break ;
			}
		}
		else if (s[i] == 32 || (s[i] >= 9 && s[i] <= 13) || s[i] == c)
			i++;
	}
	return (count);
}

static char	**split(char **memory, char const *s, char c, char **temp)
{
	int		i;
	int		j;

	i = 0;
	temp = memory;
	while (s[i])
	{
		if (s[i] != 32 && !(s[i] >= 9 && s[i] <= 13) && s[i] != c)
		{
			j = i;
			while ((s[i] != 32 && !(s[i] >= 9 && s[i] <= 13)) \
			&& s[i] != '\0' && s[i] != c)
				i++;
			if (s[i] == 32 || (s[i] >= 9 && s[i] <= 13) \
			|| s[i] == 0 || s[i] == c)
			{
				*temp = ft_substr(s, j, i - j);
				temp++;
			}
		}
		else
			i++;
	}
	*temp = 0;
	return (memory);
}

char	**ft_split(char const *s, char c)
{
	char	**memory;
	char	*temp;

	temp = NULL;
	if (!s)
		return (NULL);
	while (*s == 32 || (*s >= 9 && *s <= 13) || *s == c)
	{
		s++;
		if (*s == 0)
			return (NULL);
	}
	memory = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!memory)
		return (NULL);
	return (split(memory, s, c, &temp));
}
/*
int main ()
{
	int i;
	i = 0;
	char **result;
	char *str = "loremisus. Suspendisse";
	result = ft_split(str, ' ');

	while (result && result[i])
	{
		printf("%s\n", result[i]);
//		printf("%lu\n", ft_strlen(result[i]));
		i++;
	}
}
*/

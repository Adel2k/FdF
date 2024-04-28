#include "fdf.h"

char	*ft_strchr(const char *str, const int c)
{
	char	*ptr;

	ptr = (char *)str;
	while (1)
	{
		if (*ptr == (unsigned char)c)
			return (ptr);
		if (*ptr == '\0')
			break ;
		ptr++;
	}
	return (NULL);
}












static size_t	word_count1(const char *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
			{
				i++;
				if (s[i] == 0)
					break ;
			}
		}
		else if (s[i] == c)
			i++;
	}
	return (count);
}

static char	**split1(char **memory, char const *s, char c)
{
	int		i;
	int		j;
	char	**temp;

	i = 0;
	temp = memory;
	while (s[i] != '\0' )
	{
		if (s[i] != c)
		{
			j = i;
			while (s[i] != c && s[i] != '\0')
				i++;
			if ((s[i] == c || s[i] == '\0'))
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

char	**alt_split(char const *s, char c)
{
	char	**memory;

	if (!s)
		return (NULL);
	memory = (char **)malloc(sizeof(char *) * (word_count1(s, c) + 1));
	if (!memory)
		return (NULL);
	return (split1(memory, s, c));
}
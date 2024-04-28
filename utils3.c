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

t_gradient	*init_row(char **line)
{
	t_gradient	*res;
	int	len;

	len = line_count(line);
	res = malloc(sizeof(t_gradient) * len);
	malloc_check(res);
	return (res);
}
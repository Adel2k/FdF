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
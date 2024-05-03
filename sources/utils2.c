/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeminian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:58:03 by aeminian          #+#    #+#             */
/*   Updated: 2024/04/29 21:59:21 by aeminian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	line_count(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	map_len(t_map *map)
{
	int	len;

	len = 0;
	while (map)
	{
		len++;
		map = map -> next;
	}
	return (len);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	numb;

	i = 0;
	sign = 1;
	numb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i + 1] == 0)
			error_handle("Error!\n");
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		numb = (numb * 10) + (str[i] - '0');
		i++;
	}
	if (numb > INT_MAX || numb < INT_MIN)
		error_handle("Big number!!\n");
	return (numb * sign);
}

int	ft_atoi_base(char *str)
{
	int	i;
	int	sign;
	int	numb;

	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (str[i] == '0')
	{
		i++;
		if (str[i] == 'x')
			i++;
	}
	numb = convert_to_hex(&str[i]);
	return (sign * numb);
}

int	convert_to_hex(char *str)
{
	int		i;
	int		len;
	char	digit;
	int		numb;

	len = ft_strlen(str);
	i = 0;
	numb = 0;
	while (i < len)
	{
		digit = str[len - 1 - i];
		if (digit >= '0' && digit <= '9')
			numb += (digit - '0') * pow(16, i);
		else
			numb += (digit - 'a' + 10) * pow(16, i);
		i++;
	}
	return (numb);
}

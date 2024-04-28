/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeminian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 19:47:05 by aeminian          #+#    #+#             */
/*   Updated: 2024/04/27 20:30:25 by aeminian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_fdf(char *input, char *str)
{
	int	len;
	int	j;

	len = (ft_strlen(input) - 4);
	if (!input)
		return (1);
	j = 0;
	if (input[len] == 0)
		return (1);
	while (str[j])
	{
		if (input[len] == str[j])
		{
			if (input[len + 1] != str[j + 1])
				return (1);
			j++;
		}
		len++;
	}
	return (0);
}

void	arguments_check(int ac, char **av)
{
	if (ac <= 1)
	{
		write(2, "Please enter the file name!\n", 29);
		exit(EXIT_SUCCESS);
	}
	else if (ac > 2)
	{
		write(2, "Too many arguments!\n", 21);
		exit(EXIT_FAILURE);
	}
	else if (is_fdf(av[1], ".fdf"))
	{
		write(2, "Invalid argument!\n", 19);
		write(2, "Enter a file in <name>.fdf format.\n", 36);
		exit(EXIT_FAILURE);
	}
}

t_map	*parser(int fd, t_mlx_vars *vars)
{
	char	*buffer;
	t_map	*map;

	vars->height_size = 0;
	vars->width_size = 0;
	while (1)
	{
		buffer = get_next_line(fd);
		if (buffer == 0)
			break ;
		add_to_map(&map, buffer);
		free(buffer);
	}
	return (map);
}

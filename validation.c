/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeminian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 19:47:05 by aeminian          #+#    #+#             */
/*   Updated: 2024/04/29 21:52:47 by aeminian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	do_atoi(t_mlx_vars **vars, t_map *map, int j, int i)
{
	char	**info;
	int		k;

	k = 0;
	if (strchr(map->line[j], ','))
	{
		info = ft_split(map->line[j], ',');
		(*vars)->coordinates[i][j].z = ft_atoi(info[0]);
		(*vars)->coordinates[i][j].color = ft_atoi_base(info[1]);
		while (info[k])
		{
			free(info[k]);
			k++;
		}
		free(info);
	}
	else
	{
		(*vars)->coordinates[i][j].z = ft_atoi(map->line[j]);
		(*vars)->coordinates[i][j].color = 135;
	}
}

void	do_matrix(t_mlx_vars **vars, t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (i < (*vars)->height_size)
	{
		if ((*vars)->width_size != line_count(map->line))
			error_handle("Invalid map!\n");
		(*vars)->coordinates[i] = init_row(map->line);
		j = 0;
		while (map->line[j])
		{
			do_atoi(vars, map, j, i);
			j++;
		}
		map = map->next;
		i++;
	}
}

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

t_map	*parser(int fd, t_mlx_vars *vars)
{
	char	*buffer;
	t_map	*map;

	vars->height_size = 0;
	vars->width_size = 0;
	map = NULL;
	while (1)
	{
		buffer = get_next_line(fd);
		if (buffer == NULL)
			break ;
		add_to_map(&map, buffer);
		free(buffer);
	}
	vars->map_ = map;
	return (map);
}

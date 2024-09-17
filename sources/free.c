/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeminian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:53:02 by aeminian          #+#    #+#             */
/*   Updated: 2024/04/29 21:53:56 by aeminian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_matrix(t_map *map, t_mlx_vars *vars)
{
	free_map(map);
	free_vars(vars);
}

void	free_map(t_map *map)
{
	t_map	*tmp;
	int		i;

	while (map)
	{
		tmp = map -> next;
		i = 0;
		while ((map->line)[i])
			free((map -> line)[i++]);
		free(map->line);
		free(map);
		map = tmp;
	}
}

void	free_vars(t_mlx_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->height_size)
	{
		free(vars->coordinates[i]);
		i++;
	}
	free(vars->coordinates);
}

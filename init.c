/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeminian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:56:34 by aeminian          #+#    #+#             */
/*   Updated: 2024/04/29 21:57:41 by aeminian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	add_to_map(t_map **map, char *str)
{
	t_map	*new;
	t_map	*temp;

	if (!map)
		return ;
	new = malloc(sizeof(t_map));
	malloc_check(new);
	new->line = ft_split(str, ' ');
	if (!new->line)
	{
		free(new);
		error_handle("Split error\n");
	}
	new->next = NULL;
	temp = *map;
	if (!temp)
		*map = new;
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
}

int	line_size(t_mlx_vars *vars)
{
	if (vars->height_size <= 10 && vars->width_size <= 10)
		return (100);
	else if (vars->height_size <= 25 && vars->width_size <= 25)
		return (30);
	else if (vars->height_size <= 50 && vars->width_size <= 50)
		return (20);
	else if (vars->height_size <= 100 && vars->width_size <= 100)
		return (10);
	else if (vars->height_size <= 200 && vars->width_size <= 200)
		return (5);
	else
		return (2);
}

void	init_vars(t_mlx_vars **vars, t_map *map)
{
	(*vars)->height_size = map_len(map);
	(*vars)->width_size = line_count(map->line);
	(*vars)->coordinates = malloc(sizeof(t_gradient *) \
	* ((*vars)->height_size));
	malloc_check((*vars)->coordinates);
	do_matrix(vars, map);
	(*vars)->mlx = NULL;
	(*vars)->win = NULL;
	(*vars)->x = 1500;
	(*vars)->y = 1000;
	(*vars)->x_start = (*vars)->width_size / 2 + 450;
	(*vars)->y_start = ((*vars)->height_size / 2) + 250;
	(*vars)->x_end = (*vars)->x - (*vars)->x_start;
	(*vars)->y_end = (*vars)->y - (*vars)->y_start;
	(*vars)->dx = (*vars)->x_end - (*vars)->x_start;
	(*vars)->dy = (*vars)->y_end - (*vars)->y_start;
	(*vars)->line = line_size(*vars);
	(*vars)->zoom = zoom(*vars);
	(*vars)->view = 0;
	(*vars)->tetha = 0;
	(*vars)->gamma = 0;
	(*vars)->alpha = 0.00;
	(*vars)->rotate = 45;
}

void	count_dif(t_coordinates	*xy)
{
	if (xy->dy_abs > xy->dx_abs)
	{
		xy->max = xy->dy_abs;
		xy->min = xy->dx_abs;
	}
}

t_coordinates	setting_vars(int x1, int y1, int x2, int y2)
{
	t_coordinates	xy;

	xy.dx = x2 - x1;
	xy.dy = y2 - y1;
	xy.dx_abs = xy.dx;
	if (xy.dx < 0)
		xy.dx_abs = -xy.dx;
	xy.dy_abs = xy.dy;
	if (xy.dy < 0)
		xy.dy_abs = -xy.dy;
	xy.sx = 1;
	if (xy.dx < 0)
		xy.sx = -1;
	xy.sy = 1;
	if (xy.dy < 0)
		xy.sy = -1;
	xy.x = x1;
	xy.y = y1;
	xy.max = xy.dx_abs;
	xy.min = xy.dy_abs;
	count_dif(&xy);
	xy.p = 2 * xy.min - xy.max;
	return (xy);
}

#include "fdf.h"

t_gradient	*init_row(char **line)
{
	t_gradient	*res;
	int	len;

	len = line_count(line);
	res = malloc(sizeof(t_gradient) * len);
	malloc_check(res);
	return (res);
}

void	add_to_map(t_map **map, char *str)
{
	t_map	*new;
	t_map	*temp;

	if (!map)
		return ;
	new = malloc(sizeof(t_map));
	if (!new)
		return ;
	new->line = ft_split(str, ' ');
	new->next = NULL;
	temp = *map;
	if (!temp)
		*map = new;
	else
	{
		while (temp && temp->next)
			temp = temp->next;
		temp->next = new;
	}
}
int	line_size(t_mlx_vars *vars)
{
	if (vars->height_size <= 10 && vars->width_size <= 10)
		return (200);
	else if (vars->height_size <= 25 && vars->width_size <= 25)
		return (40);
	else if (vars->height_size <= 50 && vars->width_size <= 50)
		return (30);
	else if (vars->height_size <= 100 && vars->width_size <= 100)
		return (20);
	else if (vars->height_size <= 200 && vars->width_size <= 200)
		return (15);
	else if (vars->height_size <= 150 && vars->width_size <= 150)
		return (10);
	else
		return (5);
}

void	do_matrix(t_mlx_vars **vars, t_map *map)
{
	int		i;
	int		j;
	char	**info;

	i = 0;
	while (i < (*vars)->height_size)
	{
		if ((*vars)->width_size != line_count(map->line))
			error_handle("Invalid map!\n");
		(*vars)->coordinates[i] = init_row(map->line);
		j = 0;
		while (map->line[j])
		{
			if (strchr(map->line[j], ','))
			{
				info = ft_split(map->line[j], ',');
				(*vars)->coordinates[i][j].z = ft_atoi(info[0]);
				(*vars)->coordinates[i][j].color = ft_atoi_base(info[1]);
			}
			else
			{
				(*vars)->coordinates[i][j].z = ft_atoi(map->line[j]);
				(*vars)->coordinates[i][j].color = 85;
			}
			j++;
		}
		map = map->next;
		i++;
	}
}
void	init_vars(t_mlx_vars **vars, t_map *map)
{

	(*vars)->height_size = map_len(map);
	(*vars)->width_size = line_count(map->line);
	(*vars)->coordinates = malloc(sizeof(t_gradient *) * ((*vars)->height_size));
	malloc_check((*vars)->coordinates);
	do_matrix(vars, map);
	(*vars)->mlx = NULL;
	(*vars)->win = NULL;
	(*vars)->x = 1500;
	(*vars)->y = 1000;
	(*vars)->x_start = (*vars)->x / 2;
	(*vars)->y_start = -500;
	(*vars)->x_end = (*vars)->x - (*vars)->x_start;
	(*vars)->y_end = (*vars)->y - (*vars)->y_start;
	(*vars)->dx = (*vars)->x_end - (*vars)->x_start;
	(*vars)->dy = (*vars)->y_end - (*vars)->y_start;
	(*vars)->line = line_size(*vars);
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
	if (xy.dy_abs > xy.dx_abs)
	{
		xy.max = xy.dy_abs;
		xy.min = xy.dx_abs;
	}
	xy.p = 2 * xy.min - xy.max;
	return (xy);
}
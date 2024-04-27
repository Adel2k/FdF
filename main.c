/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeminian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 18:52:13 by aeminian          #+#    #+#             */
/*   Updated: 2024/04/27 19:01:25 by aeminian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	free(vars);
}

int	main(int ac, char **av)
{
	int			fd;
	t_mlx_vars	*vars;
	t_map		*map;

	vars = malloc(sizeof(t_mlx_vars));
	arguments_check(ac, av);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		error_handle("Invalid fd!\n");
	map = parser(fd, vars);
	if (!map)
		return (0);
	init_vars(&vars, map);
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
		error_handle("MLX initialization failed!\n");
	vars->win = mlx_new_window(vars->mlx, vars->x, vars->y, "FdF");
	if (vars->win == NULL)
		error_handle("MLX connection failed!\n");
	vars->img.img_ptr = mlx_new_image(vars->mlx, vars->x, vars->y);
	vars->img.img_pixels_ptr = mlx_get_data_addr(vars->img.img_ptr, &vars->img.bits_per_pixel, &vars->img.line_len, &vars->img.endian);
	map_generating(vars);
	mlx_hook(vars->win, 17, 0, mouse_close, vars);
	mlx_key_hook(vars->win, handler, vars);
	mlx_loop(vars->mlx);
	free_map(map);
	free_vars(vars);
}

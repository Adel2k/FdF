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

char	*file_name(char *name)
{
	char	*res;
	int		len;
	char	*temp;

	len = 0;
	temp = name;
	while (*temp != '.')
	{
		temp++;
		len++;
	}
	res = malloc(len + 1);
	temp = res;
	while (*name != '.')
	{
		*res = *name;
		name++;
		res++;
	}
	*res = 0;
	return (temp);
}
void	starting(int fd, char *name)
{
	t_mlx_vars	*vars;
	t_map		*map;

	vars = malloc(sizeof(t_mlx_vars));
	map = parser(fd, vars);
	if (!map)
		error_handle("Something went wrong!\n");
	init_vars(&vars, map);
	vars->name = file_name(name);

	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
		error_handle("MLX initialization failed!\n");
	vars->win = mlx_new_window(vars->mlx, vars->x, vars->y, "FdF");
	if (vars->win == NULL)
		error_handle("MLX connection failed!\n");
	vars->img.img_ptr = mlx_new_image(vars->mlx, vars->x - 150, vars->y);
	vars->img.img_pixels_ptr = mlx_get_data_addr(vars->img.img_ptr, &vars->img.bits_per_pixel, \
	&vars->img.line_len, &vars->img.endian);
	map_generating(vars);
	mlx_hook(vars->win, 17, 0, mouse_close, vars);
	mlx_key_hook(vars->win, handler, vars);
	mlx_loop(vars->mlx);
	free_matrix(map, vars);
}

int	main(int ac, char **av)
{
	int			fd;

	if (ac == 2)
	{
		if (is_fdf(av[1], ".fdf"))
			error_handle("Invalid argument!\nEnter a file in <name>.fdf format.\n");
		fd = open(av[1], O_RDONLY);
		if (fd < 0)
			error_handle("Invalid fd!\n");
		starting(fd, av[1]);
	}
	else if (ac > 2)
		error_handle("Too many arguments!\nPlease just enter the file name.\n");
	else
	{
		write(2, "Please enter the file name!\n", 29);
		exit(EXIT_SUCCESS);
	}
}

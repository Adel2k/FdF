/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeminian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 19:20:20 by aeminian          #+#    #+#             */
/*   Updated: 2024/04/29 21:37:35 by aeminian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_image_clear(t_img *data, t_mlx_vars *vars)
{
	int	offset;

	offset = 0;
	while (offset < (vars->y * data->line_len))
	{
		*(data->img_pixels_ptr + offset) = 0x0;
		offset++;
	}
}

void	first_pos(t_mlx_vars *vars)
{
	vars->rotate = 45;
	vars->view = 0;
	vars->gamma = 0;
	vars->x_start = vars->width_size / 2 + 350;
	vars->y_start = (vars->height_size / 2) + 250;
	vars->zoom = zoom(vars);
	vars->line = line_size(vars);
}

int	handler(int keysym, t_mlx_vars *vars)
{
	if (keysym == 53)
	{
		mlx_destroy_image(vars->mlx, vars->img.img_ptr);
		mlx_clear_window(vars->mlx, vars->win);
		mlx_destroy_window(vars->mlx, vars->win);
		free_vars(vars);
		exit(0);
	}
	if (keysym == 49)
		first_pos(vars);
	if (keysym == 69 || keysym == 78 || keysym == 24 || keysym == 27)
		zooming(keysym, vars);
	if (keysym == 126 || keysym == 125 || keysym == 124 || keysym == 123)
		position(keysym, vars);
	if (keysym == 82 || keysym == 83 || keysym == 84 || keysym == 85)
		view(keysym, vars);
	mlx_clear_window(vars->mlx, vars->win);
	my_image_clear(&vars->img, vars);
	map_generating(vars);
	return (0);
}

int	mouse_close(t_mlx_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.img_ptr);
	mlx_clear_window(vars->mlx, vars->win);
	mlx_destroy_window(vars->mlx, vars->win);
	free_vars(vars);
	exit(0);
	return (0);
}

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

void	zooming(int keysym, t_mlx_vars *vars)
{
	if (keysym == 69 || keysym == 24)
		vars->line += 1;
	if (keysym == 78 || keysym == 27)
		vars->line -= 1;
}

void	position(int keysym, t_mlx_vars *vars)
{
	if (keysym == 126)
		vars->y_start -= 5;
	if (keysym == 125)
		vars->y_start += 5;
	if (keysym == 124)
		vars->x_start += 5;
	if (keysym == 123)
		vars->x_start -= 5;
}

int	handler(int keysym, t_mlx_vars *vars)
{
	if (keysym == 53)
	{
		mlx_destroy_image(vars->mlx, vars->img.img_ptr);
		mlx_clear_window(vars->mlx, vars->win);
		mlx_destroy_window(vars->mlx, vars->win);
		free(vars->mlx);
		exit(0);
	}
	if (keysym == 69 || keysym == 24 || keysym == 78 || keysym == 27)
		zooming(keysym, vars);
	if (keysym == 126 || keysym == 125 || keysym == 124 || keysym == 123)
		position(keysym, vars);
	mlx_clear_window(vars->mlx, vars->win);
	mlx_destroy_image(vars->mlx, vars->img.img_ptr);
	vars->img.img_ptr = mlx_new_image(vars->mlx, vars->x - 150, vars->y);
	vars->img.img_pixels_ptr = mlx_get_data_addr(vars->img.img_ptr, \
	&vars->img.bits_per_pixel, &vars->img.line_len, &vars->img.endian);
	map_generating(vars);
	return (0);
}

int	mouse_close(t_mlx_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.img_ptr);
	mlx_clear_window(vars->mlx, vars->win);
	mlx_destroy_window(vars->mlx, vars->win);
	free(vars->mlx);
	exit(0);
	return (0);
}

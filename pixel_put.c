/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeminian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 19:22:52 by aeminian          #+#    #+#             */
/*   Updated: 2024/04/29 21:40:33 by aeminian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (0 < x && x < 1300 && 0 < y && 1000 > y)
	{
		dst = img->img_pixels_ptr + (y * img->line_len + \
		x * (img->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

float	find_max(float x, float y)
{
	if (x > y)
		return (x);
	return (y);
}

void	bresnham(t_mlx_vars *vars, t_coordinates *xy)
{
	int	i;

	i = 0;
	while (i <= xy->max)
	{
		my_pixel_put(&vars->img, xy->x, xy->y, vars->color);
		if (xy->p >= 0)
		{
			if (xy->dx_abs > xy->dy_abs)
				xy->y += xy->sy;
			else
				xy->x += xy->sx;
			xy->p -= 2 * xy->max;
		}
		if (xy->dx_abs > xy->dy_abs)
			xy->x += xy->sx;
		else
			xy->y += xy->sy;
		xy->p += 2 * xy->min;
		i++;
	}
}

void	mlx_side2(t_mlx_vars *vars)
{
	mlx_string_put(vars->mlx, vars->win, 25, 170, 0xb78f3f, \
	"Change the positions with");
	mlx_string_put(vars->mlx, vars->win, 25, 195, 0xb78f3f, \
	"'right', 'left', 'up', 'down'" );
	mlx_string_put(vars->mlx, vars->win, 25, 220, 0xb78f3f, \
	"For height press 'ctrl + '='");
	mlx_string_put(vars->mlx, vars->win, 25, 245, 0xb78f3f, \
	"Top view = '1'");
	mlx_string_put(vars->mlx, vars->win, 25, 265, 0xb78f3f, \
	"Right view = '2'");
	mlx_string_put(vars->mlx, vars->win, 25, 285, 0xb78f3f, \
	"First position = 'space'");
	mlx_string_put(vars->mlx, vars->win, 25, 305, 0xb78f3f, \
	"For rotate hold the '1' or '2'");
	mlx_string_put(vars->mlx, vars->win, 25, 365, 0xb78f3f, \
	"For exit press'ESC.'");
	mlx_string_put(vars->mlx, vars->win, 25, 900, 0xb78f3f, \
	"Thank you!!");
}

void	mlx_side(t_mlx_vars *vars)
{
	t_coordinates	side;

	side = setting_vars(2, 0, 2, 1000);
	vars->color = 0xececdd;
	bresnham(vars, &side);
	mlx_string_put(vars->mlx, vars->win, 60, 50, 0x4f7ebb, \
	"Welcome to Penguin's FdF<3");
	mlx_string_put(vars->mlx, vars->win, 60, 70, 0x4f7ebb, \
	"Isometric projection 3D");
	mlx_string_put(vars->mlx, vars->win, 60, 90, 0x4f7ebb, "Map Name: ");
	mlx_string_put(vars->mlx, vars->win, 160, 90, 0xececdd, vars->name);
	mlx_string_put(vars->mlx, vars->win, 25, 130, 0xb78f3f, \
	"For zoom out press '+'");
	mlx_string_put(vars->mlx, vars->win, 25, 150, 0xb78f3f, \
	"For zoom in press '-'");
	mlx_side2(vars);
}

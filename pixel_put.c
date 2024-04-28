/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeminian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 19:22:52 by aeminian          #+#    #+#             */
/*   Updated: 2024/04/27 19:31:26 by aeminian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (0 < x && x < 1500 && 0 < y && 1000 > y)
	{
		dst = img->img_pixels_ptr + (y * img->line_len + x * (img->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
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
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img_ptr, 250, 0);
}
void	mlx_side(t_mlx_vars *vars)
{	
	t_coordinates side;

	side = setting_vars(0, 300, 50, 300);
	bresnham(vars, &side);
	side = setting_vars(50, 0, 50, 1000);
	bresnham(vars, &side);
	mlx_string_put(vars->mlx, vars->win, 60, 50, 255, "Welcome to Penguin's FdF<3");
	mlx_string_put(vars->mlx, vars->win, 60, 65, 255, "Isometric projection 3D");
	mlx_string_put(vars->mlx, vars->win, 60, 80, 255, "Map Name: ");
	mlx_string_put(vars->mlx, vars->win, 130, 80, 255, vars->name);
	mlx_string_put(vars->mlx, vars->win, 30, 130, 255, "For zoom out press '+'");
	mlx_string_put(vars->mlx, vars->win, 30, 150, 255, "For zoom in press '-'");
	mlx_string_put(vars->mlx, vars->win, 30, 170, 255, "Use up, down, left and write buttons");
	mlx_string_put(vars->mlx, vars->win, 30, 190, 255, "For closing press 'ESC'");

}
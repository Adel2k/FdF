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

void	bresnham(t_mlx_vars *vars, t_coordinates *xy, t_cord *ij)
{
	int	i;
	(void)ij;
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
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img_ptr, 0, 0);
}

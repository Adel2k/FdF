/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generating.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeminian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:23:11 by aeminian          #+#    #+#             */
/*   Updated: 2024/04/29 21:27:00 by aeminian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric_projection(t_points *p, t_mlx_vars *vars)
{
	rotate_x(p, vars);
	rotate_y(p, vars);
	rotate_z(p, vars);
	if (vars->view == 0)
		isometric(p, vars);
}

void	first_point(t_points *p, int x, int y, t_mlx_vars *vars)
{
	p->point1.x = (x * vars->line);
	p->point1.y = (y * vars->line);
}

void	points(t_cord *x, t_points *p, t_mlx_vars *v)
{
	if (x->x + 1 < v->width_size)
		generat(x, p, v);
	if (x->y + 1 < v->height_size)
		generat2(x, p, v);
}

void	map_generating(t_mlx_vars *vars)
{
	t_points	p;
	t_cord		xy;

	xy.y = 0;
	while (xy.y < vars->height_size)
	{
		xy.x = 0;
		while (xy.x + 1 <= vars->width_size)
		{
			points(&xy, &p, vars);
			xy.x++;
		}
		xy.y++;
	}
	mlx_side(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img_ptr, 350, 0);
}

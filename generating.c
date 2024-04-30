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

void	isometric_projection(t_points *p)
{
	rotate_x(p);
	rotate_y(p);
	rotate_z(p);
	isometric(p);
}

void	first_point(t_points *p, int x, int y, t_mlx_vars *vars)
{
	p->point1.x = vars->x_start + (x * vars->line);
	p->point1.y = vars->y_start + (y * vars->line);
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
		mlx_side(vars);
		while (xy.x + 1 <= vars->width_size)
		{
			points(&xy, &p, vars);
			xy.x++;
		}
		xy.y++;
	}
}

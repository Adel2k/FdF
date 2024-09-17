/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeminian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 19:01:33 by aeminian          #+#    #+#             */
/*   Updated: 2024/04/29 21:48:27 by aeminian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(t_points *p, t_mlx_vars *vars)
{
	t_cord	p1;
	t_cord	p2;

	p1.x = p->point1.x;
	p1.y = p->point1.y;
	p2.x = p->point2.x;
	p2.y = p->point2.y;
	p->point1.x = (p1.x - p1.y) * cos(vars->rotate);
	p->point1.y = (p1.x + p1.y) * sin(vars->rotate) - vars->zoom * p->point1.z;
	p->point2.x = (p2.x - p2.y) * cos(vars->rotate);
	p->point2.y = (p2.x + p2.y) * sin(vars->rotate) - vars->zoom * p->point2.z;
}

void	rotate_x(t_points *p, t_mlx_vars *vars)
{
	int	y1;
	int	y2;

	y1 = p->point1.y;
	y2 = p->point2.y;
	p->point1.y = y1 * cos(vars->alpha) + p->point1.z * sin(vars->alpha);
	p->point1.z = -y1 * sin(vars->alpha) + p->point1.z * cos(vars->alpha);
	p->point2.y = y2 * cos(vars->alpha) + p->point2.z * sin(vars->alpha);
	p->point2.z = y2 * sin(vars->alpha) + p->point2.z * cos(vars->alpha);
}

void	rotate_y(t_points *p, t_mlx_vars *vars)
{
	int	x1;
	int	x2;

	x1 = p->point1.x;
	x2 = p->point2.x;
	p->point1.x = x1 * cos(vars->tetha) + p->point1.z * sin(vars->tetha);
	p->point1.z = -x1 * sin(vars->tetha) + p->point1.z * cos(vars->tetha);
	p->point2.x = x2 * cos(vars->tetha) + p->point2.z * sin(vars->tetha);
	p->point2.z = -x2 * sin(vars->tetha) + p->point2.z * cos(vars->tetha);
}

void	rotate_z(t_points *p, t_mlx_vars *vars)
{
	int	prev_x1;
	int	prev_x2;

	prev_x1 = p->point1.x;
	prev_x2 = p->point2.x;
	p->point1.x = prev_x1 * cos(vars->gamma) - p->point1.y * sin(vars->gamma);
	p->point1.y = prev_x1 * sin(vars->gamma) + p->point1.y * cos(vars->gamma);
	p->point2.x = prev_x2 * cos(vars->gamma) - p->point2.y * sin(vars->gamma);
	p->point2.y = prev_x2 * sin(vars->gamma) + p->point2.y * cos(vars->gamma);
}

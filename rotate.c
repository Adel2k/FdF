/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeminian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 19:01:33 by aeminian          #+#    #+#             */
/*   Updated: 2024/04/27 19:02:38 by aeminian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(t_points *p)
{
	t_cord	p1;
	t_cord	p2;

	p1.x = p->point1.x;
	p1.y = p->point1.y;
	p2.x = p->point2.x;
	p2.y = p->point2.y;
	p->point1.x = (p1.x - p1.y) * cos(M_PI / 4);
	p->point1.y = (p1.x + p1.y) * sin(M_PI / 4) - 10 * p->point1.z;
	p->point2.x = (p2.x - p2.y) * cos(M_PI / 4);
	p->point2.y = (p2.x + p2.y) * sin(M_PI / 4) - 10 * p->point2.z;
}

void	rotate_x(t_points *p)
{
	int	y1;
	int	y2;

	y1 = p->point1.y;
	y2 = p->point2.y;
	p->point1.y = y1 * cos(0.00) + p->point1.z * sin(0.00);
	p->point1.z = -y1 * sin(0.00) + p->point1.z * cos(0.00);
	p->point2.y = y2 * cos(0.00) + p->point2.z * sin(0.00);
	p->point2.z = y2 * sin(0.00) + p->point2.z * cos(0.00);
}

void	rotate_y(t_points *p)
{
	int	x1;
	int	x2;

	x1 = p->point1.x;
	x2 = p->point2.x;
	p->point1.x = x1 * cos(0.00) + p->point1.z * sin(0.00);
	p->point1.z = -x1 * sin(0.00) + p->point1.z * cos(0.00);
	p->point2.x = x2 * cos(0.00) + p->point2.z * sin(0.00);
	p->point2.z = -x2 * sin(0.00) + p->point2.z * cos(0.00);
}

void	rotate_z(t_points *p)
{
	int	prev_x1;
	int	prev_x2;

	prev_x1 = p->point1.x;
	prev_x2 = p->point2.x;
	p->point1.x = prev_x1 * cos(0.00) - p->point1.y * sin(0.00);
	p->point1.y = prev_x1 * sin(0.00) + p->point1.y * cos(0.00);
	p->point2.x = prev_x2 * cos(0.00) - p->point2.y * sin(0.00);
	p->point2.y = prev_x2 * sin(0.00) + p->point2.y * cos(0.00);
}
// void	rotate_y(int *x, int *z, double y_angle)
// {
// 	int	prev_x;

// 	prev_x = *x;
// 	*x = prev_x * cos(y_angle) + *z * sin(y_angle);
// 	*z = prev_x * -sin(y_angle) + *z * cos(y_angle);
// }
// void	rotate_z(int *x, int *y, double z_angle)
// {
// 	t_cord	prev;

// 	prev.x = *x;
// 	prev.y = *y;
// 	*x = prev.x * cos(z_angle) - prev.y * sin(z_angle);
// 	*y = prev.x * sin(z_angle) + prev.y * cos(z_angle);
// }

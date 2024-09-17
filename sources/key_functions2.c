/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeminian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:50:49 by aeminian          #+#    #+#             */
/*   Updated: 2024/05/01 15:50:51 by aeminian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zooming(int keysym, t_mlx_vars *vars)
{
	if (keysym == XK_w)
		vars->line += 1;
	if (keysym == XK_s && vars->line != 0)
		vars->line -= 1;
	if (keysym == 61)
		vars->zoom += 1;
	if (keysym == 45 && vars->zoom != 0)
		vars->zoom -= 1;
}

void	position(int keysym, t_mlx_vars *vars)
{
	if (keysym == XK_Up)
		vars->y_start -= 5;
	if (keysym == XK_Down)
		vars->y_start += 5;
	if (keysym == XK_Right)
		vars->x_start += 5;
	if (keysym == XK_Left)
		vars->x_start -= 5;
}

void	view(int keysym, t_mlx_vars *vars)
{
	vars->rotate = M_PI_4;
	vars->view = 0;
	if (keysym == XK_1)
	{
		vars->gamma = 0;
		vars->view = 1;
	}
	if (keysym == XK_2)
	{
		vars->rotate = -47;
		vars->gamma += 0.1;
	}
	if (keysym == XK_3)
		vars->gamma += 0.1;
}

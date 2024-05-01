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
	if (keysym == 69)
		vars->line += 1;
	if (keysym == 78)
		vars->line -= 1;
	if (keysym == 24)
		vars->zoom += 2;
	if (keysym == 27)
		vars->zoom -= 2;
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

void	view(int keysym, t_mlx_vars *vars)
{
	vars->rotate = 45;
	vars->view = 0;
	if (keysym == 83)
	{
		vars->gamma = 0;
		vars->view = 1;
	}
	if (keysym == 84)
	{
		vars->rotate = -47;
		vars->gamma += 0.1;
	}
	if (keysym == 85)
		vars->gamma += 0.1;
}

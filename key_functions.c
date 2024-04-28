/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeminian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 19:20:20 by aeminian          #+#    #+#             */
/*   Updated: 2024/04/27 19:22:27 by aeminian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zooming(int keysym, t_mlx_vars *vars)
{
	if (keysym == XK_plus)
		vars->line += 1;
	else
		vars->line -= 1;
}
void position(int keysym, t_mlx_vars *vars)
{
	if (keysym == XK_Up)
		vars->x_start -= 1;
	if (keysym == XK_Down)
		vars->x_start += 1;
	if (keysym == XK_Left)
		vars->y_start -= 1;
	if (keysym == XK_Right)
		vars->x_start += 1;
}
int	handler(int keysym, t_mlx_vars *vars)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_image(vars->mlx, vars->img.img_ptr);
		free(vars->mlx);
		exit(0);
	}
	if (keysym == XK_plus || keysym == XK_minus)
		zooming(keysym, vars);
	if (keysym == XK_Up || keysym == XK_Down|| keysym == XK_Right || keysym == XK_Left)
		position(keysym, vars);
	mlx_clear_window(vars->mlx, vars->win);
	map_generating(vars);
	return (0);
}

int	mouse_close(t_mlx_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_image(vars->mlx, vars->img.img_ptr);
	free(vars->mlx);
	exit(0);
	return (0);
}

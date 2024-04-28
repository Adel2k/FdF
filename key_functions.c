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
		printf("%d\n", vars->line);
	
	vars->line -= 50;
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

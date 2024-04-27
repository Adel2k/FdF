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

int	handler(int keysym, t_mlx_vars *vars)
{
	if (keysym == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_image(vars->mlx, vars->img.img_ptr);
		free(vars->mlx);
		exit(0);
	}
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

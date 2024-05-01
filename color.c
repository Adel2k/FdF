/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeminian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:43:00 by aeminian          #+#    #+#             */
/*   Updated: 2024/04/29 21:45:18 by aeminian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	r(int color)
{
	return ((color >> 16) & 0xFF);
}

int	g(int color)
{
	return ((color >> 8) & 0xFF);
}

int	b(int color)
{
	return (color & 0xFF);
}

int	rgb(int red, int green, int blue)
{
	return ((red << 16) + (green << 8) + blue);
}

int	gradient(int startcolor, int endcolor, int pix, t_mlx_vars *vars)
{
	double	increment[3];
	int		new[3];
	int		newcolor;

	increment[0] = (double)((r(endcolor)) - \
	(r(startcolor))) / (double)vars->width_size;
	increment[1] = (double)((g(endcolor)) - \
	(g(startcolor))) / (double)vars->width_size;
	increment[2] = (double)((b(endcolor)) - \
	(b(startcolor))) / (double)vars->width_size;
	new[0] = (r(startcolor)) + (pix * increment[0]);
	new[1] = (g(startcolor)) + (pix * increment[1]);
	new[2] = (b(startcolor)) + (pix * increment[2]);
	newcolor = rgb(new[0], new[1], new[2]);
	return (newcolor);
}

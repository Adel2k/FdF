/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeminian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:40:42 by aeminian          #+#    #+#             */
/*   Updated: 2024/04/29 21:42:52 by aeminian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_strchr(const char *str, const int c)
{
	char	*ptr;

	ptr = (char *)str;
	while (1)
	{
		if (*ptr == (unsigned char)c)
			return (ptr);
		if (*ptr == '\0')
			break ;
		ptr++;
	}
	return (NULL);
}

t_gradient	*init_row(char **line)
{
	t_gradient	*res;
	int			len;

	len = line_count(line);
	res = malloc(sizeof(t_gradient) * len);
	malloc_check(res);
	return (res);
}

void	generat(t_cord *x, t_points *p, t_mlx_vars *v)
{
	t_coordinates	t;

	first_point(p, x->x, x->y, v);
	p->point2.x = v->x_start + (x->x + 1) * v->line;
	p->point2.y = v->y_start + x->y * v->line;
	p->point1.z = v->coordinates[x->y][x->x].z;
	p->point2.z = v->coordinates[x->y][x->x + 1].z;
	isometric_projection(p);
	t = setting_vars(p->point1.x, p->point1.y, p->point2.x, p->point2.y);
	v->color = gradient(v->coordinates[x->y][x->x].color, \
	v->coordinates[x->y][x->x + 1].color, x->x, v);
	bresnham(v, &t);
}

void	generat2(t_cord *x, t_points *p, t_mlx_vars *v)
{
	t_coordinates	t;

	first_point(p, x->x, x->y, v);
	p->point2.x = v->x_start + x->x * v->line;
	p->point2.y = v->y_start + (x->y + 1) * v->line;
	p->point1.z = v->coordinates[x->y][x->x].z;
	p->point2.z = v->coordinates[x->y + 1][x->x].z;
	isometric_projection(p);
	t = setting_vars(p->point1.x, p->point1.y, p->point2.x, p->point2.y);
	v->color = gradient(v->coordinates[x->y][x->x].color, \
	v->coordinates[x->y + 1][x->x].color, x->x, v);
	bresnham(v, &t);
}

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
	p->point1.x = vars->x_start + (x * 15);
	p->point1.y = vars->y_start + (y * 15);
}

void	points(t_cord *xy, t_points *p, t_mlx_vars *vars)
{
	t_coordinates	temp;

	if (xy->x + 1 < vars->width_size)
	{
		first_point(p, xy->x, xy->y, vars);
		p->point2.x = vars->x_start + (xy->x + 1) * 15;
		p->point2.y = vars->y_start + xy->y * 15;
		p->point1.z = vars->coordinates[xy->y][xy->x].z;
		p->point2.z = vars->coordinates[xy->y][xy->x + 1].z;
		isometric_projection(p);
		temp = setting_vars(p->point1.x, p->point1.y, p->point2.x, p->point2.y);
		bresnham(vars, &temp, xy);
	}
	if (xy->y + 1 < vars->height_size)
	{
		first_point(p, xy->x, xy->y, vars);
		p->point2.x = vars->x_start + xy->x * 15;
		p->point2.y = vars->y_start + (xy->y + 1) * 15;
		p->point1.z = vars->coordinates[xy->y][xy->x].z;
		p->point2.z = vars->coordinates[xy->y + 1][xy->x].z;
		isometric_projection(p);
		temp = setting_vars(p->point1.x, p->point1.y, p->point2.x, p->point2.y);
		bresnham(vars, &temp, xy);
	}
}

void	map_generating(t_mlx_vars *vars)
{
	t_points	p;
	t_cord		xy;

	xy.y = 0;
	while (xy.y < vars->height_size)
	{
		xy.x = 0;
		while (xy.x + 1 <= vars->width_size)
		{
			points(&xy, &p, vars);
			xy.x++;
		}
		xy.y++;
	}
}
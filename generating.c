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
	p->point1.x = vars->x_start + (x * vars->line);
	p->point1.y = vars->y_start + (y * vars->line);
}


int gradient(int startcolor, int endcolor, int pix, t_mlx_vars *vars)
{
    double increment[3];
    int new[3];
    int newcolor;

    increment[0] = (double)((R(endcolor)) - (R(startcolor))) / (double)vars->width_size;
    increment[1] = (double)((G(endcolor)) - (G(startcolor))) / (double)vars->width_size;
    increment[2] = (double)((B(endcolor)) - (B(startcolor))) / (double)vars->width_size;

    new[0] = (R(startcolor)) + (pix * increment[0]);
    new[1] = (G(startcolor)) + (pix * increment[1]);
    new[2] = (B(startcolor)) + (pix * increment[2]);
    newcolor = RGB(new[0], new[1], new[2]);

    return (newcolor);
}

void	points(t_cord *xy, t_points *p, t_mlx_vars *vars)
{
	t_coordinates	temp;

	if (xy->x + 1 < vars->width_size)
	{
		first_point(p, xy->x, xy->y, vars);
		p->point2.x = vars->x_start + (xy->x + 1) * vars->line;
		p->point2.y = vars->y_start + xy->y * vars->line;
		p->point1.z = vars->coordinates[xy->y][xy->x].z;
		p->point2.z = vars->coordinates[xy->y][xy->x + 1].z;
		isometric_projection(p);
		temp = setting_vars(p->point1.x, p->point1.y, p->point2.x, p->point2.y);
		vars->color = gradient(vars->coordinates[xy->y][xy->x].color, vars->coordinates[xy->y][xy->x + 1].color, xy->x,vars);
		bresnham(vars, &temp, xy);
	}
	if (xy->y + 1 < vars->height_size)
	{
		first_point(p, xy->x, xy->y, vars);
		p->point2.x = vars->x_start + xy->x * vars->line;
		p->point2.y = vars->y_start + (xy->y + 1) * vars->line;
		p->point1.z = vars->coordinates[xy->y][xy->x].z;
		p->point2.z = vars->coordinates[xy->y + 1][xy->x].z;
		isometric_projection(p);
		temp = setting_vars(p->point1.x, p->point1.y, p->point2.x, p->point2.y);
		vars->color = gradient(vars->coordinates[xy->y][xy->x].color, vars->coordinates[xy->y + 1][xy->x].color, xy->x,vars);
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

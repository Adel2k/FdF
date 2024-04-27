#include "fdf.h"

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	
	char	*dst;

	if (0 < x && x < 1500 && 0 < y && 1000 > y)
	{
		dst = img->img_pixels_ptr + (y * img->line_len + x * (img->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
	
}

void isometric_projection(t_points *p) 
{
	rotate_x(p);
	rotate_y(p);
	rotate_z(p);
	isometric(p);
}
void first_point(t_points *p, int x, int y, t_mlx_vars *vars)
{
	p->point1.x = vars->x_start + (x * 10);
	p->point1.y = vars->y_start + (y * 10);
}

void map_generating(t_mlx_vars *vars)
{
	t_points p;
	t_cord xy;
	t_coordinates temp;

	xy.y = 0;
	while (xy.y < vars->height_size )
	{
		xy.x = 0;
		while (xy.x + 1 <= vars->width_size)
		{
			if (xy.x  + 1 < vars->width_size)
			{
				first_point(&p, xy.x, xy.y, vars);
				p.point2.x = vars->x_start + (xy.x+1) * 10;
				p.point2.y = vars->y_start + xy.y * 10;
				p.point1.z = vars->coordinates[xy.y][xy.x];
				p.point2.z = vars->coordinates[xy.y][xy.x + 1];
 		 		isometric_projection(&p);
				temp = setting_vars(p.point1.x, p.point1.y, p.point2.x, p.point2.y);
				bresnham(vars, &temp);
			 }
			if (xy.y +1< vars->height_size)
			{
				first_point(&p, xy.x, xy.y, vars);
				p.point2.x = vars->x_start + xy.x * 10;
				p.point2.y = vars->y_start + (xy.y + 1)* 10;
				p.point1.z = vars->coordinates[xy.y][xy.x];
				p.point2.z = vars->coordinates[xy.y + 1][xy.x];
 				isometric_projection(&p);
				temp =setting_vars(p.point1.x, p.point1.y, p.point2.x, p.point2.y);
				bresnham(vars,&temp);
			}
			xy.x++;
		}
		xy.y++;
	}

}


void bresnham(t_mlx_vars *vars, t_coordinates *xy) 
{
	int i;

	i = 0;
    while (i <= xy->max) 
	{
		my_pixel_put(&vars->img, xy->x , xy->y, 0xff88ff);		
        if (xy->p >= 0) 
		{
            if (xy->dx_abs > xy->dy_abs)
                xy->y += xy->sy;
            else
                xy->x += xy->sx;
            xy->p -= 2 * xy->max;
        }
        if (xy->dx_abs > xy->dy_abs)
            xy->x += xy->sx;
        else 
            xy->y += xy->sy;
        xy->p += 2 * xy->min;
		i++;
	}

	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img_ptr, 0, 0);
}

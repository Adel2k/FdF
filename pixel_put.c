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
    p->point1.iso_x = (p->point1.x - p->point1.y) * cos(M_PI / 4);
    p->point1.iso_y = (p->point1.x + p->point1.y) * sin(M_PI / 4) + 0;
	p->point2.iso_x = (p->point2.x - p->point2.y) * cos(M_PI / 4);
    p->point2.iso_y = (p->point2.x + p->point2.y) * sin(M_PI / 4) + 0;
}
void init_points(t_points *p, int x, int y, t_mlx_vars *vars)
{
	p->point1.x = vars->x_start + (x * 200);
	p->point1.y = vars->y_start + (y * 200);
	if (x + 1 < vars->width_size )
	{
		p->point2.x = vars->x_start + ((x + 1 )* 200);
		p->point2.y = vars->y_start + (y * 200);
	}
	else 
	{
		p->point2.x = vars->x_start + (x * 200);
		p->point2.y = vars->y_start + (y + 1 * 200);
	}
	  for(int i = 0; i < vars->width_size; i++)
    {
        printf("%d\n", vars->coordinates[vars->height_size - 1][i]);
        printf("x=%d, y=%d\n", (vars->height_size - 1), i);

    }
	// printf("%d ,%d\n", x, y);
	// int z = vars->coordinates[x][y];
	// int z2 = vars->coordinates[x][y];
    // printf("hello\n%d%d", z, z2);
}
void map_generating(t_mlx_vars *vars)
{
	t_points p;
	t_cord xy;
	t_coordinates temp;

	xy.x = 0;
	while (xy.x < vars->width_size)
	{
		xy.y = 0;
		while (xy.y < vars->height_size)
		{
			if (xy.y + 1 < vars->height_size)
			{
				init_points(&p, xy.x, xy.y, vars);
 		 		isometric_projection(&p);
				temp = setting_vars(p.point1.iso_x, p.point1.iso_y, p.point2.iso_x, p.point2.iso_y);
				bresnham(vars, &temp);
			 }
			if (xy.x + 1< vars->width_size )
			{
				init_points(&p, xy.x, xy.y, vars);
 		 		isometric_projection(&p);
				temp =setting_vars(p.point1.iso_x, p.point1.iso_y, p.point2.iso_x, p.point2.iso_y);
				bresnham(vars,&temp);
			}
			xy.y++;
		}
		xy.x++;
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

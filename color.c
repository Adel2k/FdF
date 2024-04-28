#include "fdf.h"

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
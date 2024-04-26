#include "fdf.h"

int main(int ac, char **av)
{
    int fd;
    t_mlx_vars *vars;

    vars = malloc(sizeof(t_mlx_vars));
    arguments_check(ac, av);
    fd = open(av[1], O_RDONLY);
    if(fd < 0)
    {
        write(2, "Invalid fd!\n", 13);
        exit(EXIT_FAILURE);
    }
    parser(fd, vars);
    //    int z = vars->coordinates[4][0];
    // printf("%d\n", z);
    vars->mlx = mlx_init();
    if(vars->mlx == NULL)
        error_handle("MLX initialization failed!\n");
    vars->win = mlx_new_window(vars->mlx, vars->x, vars->y, "FdF");
    if(vars->win == NULL)
        error_handle("MLX connection failed!\n");
    vars->img.img_ptr = mlx_new_image(vars->mlx, vars->x , vars->y);
	vars->img.img_pixels_ptr = mlx_get_data_addr(vars->img.img_ptr, &vars->img.bits_per_pixel, &vars->img.line_len, &vars->img.endian);
    
   map_generating(vars);
    mlx_hook(vars->win, 17, 0, mouse_close, vars);
    mlx_key_hook(vars->win, handler, vars);
    mlx_loop(vars->mlx);
}
// #include "fdf.h"

// #include "minilibx-linux/mlx.h"

// int  handler(int keysym, t_vars *vars)
// {
//     if (keysym == XK_Escape)
//     {
//         mlx_destroy_window(vars->mlx, vars->win);
//         mlx_destroy_display(vars->mlx);
//         free(vars->mlx);
//         exit(0);
//     }
//     return 0;
// }

// int mouse_close(t_vars *vars) 
// {
//     mlx_destroy_window(vars->mlx, vars->win);
//     mlx_destroy_display(vars->mlx);
//     free(vars->mlx);
//     exit(0);
//     return 0;
// }
// void bresnham(int x1, int y1, int x2, int y2)
// {
//     int x = x1;
//     int y = y1;

//     int dx = x2 - x1;
//     int dy = y2 - y1;
//     int p = 2(dy) - dx;
//     while (x <= x2)
//     {
//         mlx_put
//     }
    
// }


// void  window(void)
// {
//     t_vars window;

//     window.mlx = mlx_init();
//     window.win = mlx_new_window(window.mlx, 1000, 1000, "FdF");
//     mlx_hook(window.win, 17, 0L, mouse_close, NULL);
//     mlx_key_hook(window.win, handler, &window);
//     mlx_loop(window.mlx);

// }
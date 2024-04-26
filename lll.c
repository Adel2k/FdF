// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>
// #include "minilibx-linux/mlx.h"

// #define WIDTH 800
// #define HEIGHT 600
// #define MAP_SIZE 10


// // Define a height map
// float height_map[MAP_SIZE][MAP_SIZE] = {
//    {100, 100, 100},
//    {100, 10, 100},
//    {100, 100, 100}
// };
// void draw_line(void *mlx, void *win, int x0, int y0, int x1, int y1, int color) {
//     int dx = abs(x1 - x0);
//     int dy = abs(y1 - y0);
//     int sx = (x0 < x1) ? 1 : -1;
//     int sy = (y0 < y1) ? 1 : -1;
//     int err = dx - dy;
    
//     while (1) {
//         mlx_pixel_put(mlx, win, x0, y0, color);
//         if (x0 == x1 && y0 == y1) {
//             break;
//         }
        
//         // Calculate the error term
//         int e2 = 2 * err;
//         if (e2 > -dy) {
//             err -= dy;
//             x0 += sx;
//         }
//         if (e2 < dx) {
//             err += dx;
//             y0 += sy;
//         }
//     }
// }

// // Function to project 3D coordinates to 2D isometric coordinates
// void projectToIsometric(float x, float y, float z, float *x_prime, float *y_prime) {
//     float alpha = M_PI / 6; // Isometric angle (30 degrees in radians)
//     *x_prime = (x - y) * cos(alpha);
//     *y_prime = (x + y) * sin(alpha) - z;
// }

// // Function to render the wireframe landscape using MiniLibX
// void renderWireframe(void *mlx, void *win) {
//     float x_prime, y_prime;
//     float x1_prime, y1_prime;

//     // Iterate through the height map
//     for (int y = 0; y < MAP_SIZE; y++) {
//         for (int x = 0; x < MAP_SIZE; x++) {
//             // Project the current point to isometric coordinates
//             projectToIsometric(x, y, height_map[y][x], &x_prime, &y_prime);
            
//             // Draw horizontal line connecting the current point to the point on the right
//             if (x < MAP_SIZE - 1) {
//                 projectToIsometric(x + 1, y, height_map[y][x + 1], &x1_prime, &y1_prime);
//                 draw_line(mlx, win, x_prime + WIDTH / 2, y_prime + HEIGHT / 2, x1_prime + WIDTH / 2, y1_prime + HEIGHT / 2, 0xff88ff);
//             }
            
//             // Draw vertical line connecting the current point to the point below
//             if (y < MAP_SIZE - 1) {
//                 float x2_prime, y2_prime;
//                 projectToIsometric(x, y + 1, height_map[y + 1][x], &x2_prime, &y2_prime);
//                 draw_line(mlx, win, x_prime + WIDTH / 2, y_prime + HEIGHT / 2, x2_prime + WIDTH / 2, y2_prime + HEIGHT / 2, 0xff88ff);
//             }
//         }
//     }
// }

// // Main program
// int main() {
//     // Initialize MiniLibX
//     void *mlx = mlx_init();
//     void *win = mlx_new_window(mlx, WIDTH, HEIGHT, "FdF 42 Project");

//     // Render the wireframe landscape

//     renderWireframe(mlx, win);

    
//     // Start the event loop
//     mlx_loop(mlx);

//     return 0;
// }

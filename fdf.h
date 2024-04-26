# ifndef FDF_H
# define FDF_H
# include <stdio.h>
# include <string.h>
# include <limits.h>
# include <unistd.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <math.h>
# include "get_next_line.h"

typedef struct n_img
{
    void *img_ptr;
    char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}   t_img;

typedef struct n_cord
{
	int		x;
	int		y;
    int     z;
    int     iso_x;
    int     iso_y;
}   t_cord;

typedef struct  n_points
{
    t_cord point1;
    t_cord point2;
} t_points;

typedef struct n_coordinates
{
    int x;
    int y;
    int z;
    int dx;
    int dy;
    int sx;
    int sy;
    int     dx_abs;
    int     dy_abs;
    int     p;
    int     min;
    int     max;
}  t_coordinates;

typedef struct	s_mlx_vars {
	void	*mlx;
	void	*win;
    int     **coordinates;
    t_cord  *cord;
    t_img   img;
    int     y;
    int     x;
    int     width_size;
    int     height_size;
    int     y_start;
    int     x_start;
    int     x_end;
    int     y_end;
    int     dx;
    int     dy;
    int     sx;
    int     sy;
    int     z;
    char    **row;
    int     start;
}				t_mlx_vars;

typedef struct s_map
{
  char **line;
  struct s_map  *next;
}  t_map;

int     handler(int keysym, t_mlx_vars *vars);
int     mouse_close(t_mlx_vars *vars);
void    init_vars(t_mlx_vars **vars, t_map *map);
t_map    *parser(int fd, t_mlx_vars *vars);
size_t	ft_strlen(const char *str);
void	malloc_check(void *str);
int     is_fdf(char *input, char *str);
void    arguments_check(int ac, char **av);
char	**ft_split(char const *s);
void	error_handle(char *msg);       
char	*ft_substr(char const *s, unsigned int start, size_t len);
int     count_width(char **args);
void map_generating(t_mlx_vars *vars);
void bresnham(t_mlx_vars *vars, t_coordinates *xy) ;
t_coordinates	setting_vars(int x1, int y1, int x2, int y2);

#endif
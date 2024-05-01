/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeminian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 19:03:16 by aeminian          #+#    #+#             */
/*   Updated: 2024/04/29 21:22:37 by aeminian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <string.h>
# include <limits.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
// # include <X11/keysym.h>
# include "get_next_line.h"
# include "minilibx/mlx.h"

typedef struct s_map t_map;

typedef struct n_img
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}	t_img;

typedef struct n_cord
{
	int		x;
	int		y;
	int		z;
	int		i;
	int		j;
}	t_cord;

typedef struct n_points
{
	t_cord	point1;
	t_cord	point2;
}	t_points;


typedef struct n_coordinates
{
	int	x;
	int	y;
	int	z;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	dx_abs;
	int	dy_abs;
	int	p;
	int	min;
	int	max;
}	t_coordinates;

typedef struct s_gradient
{
	int	z;
	int	color;
}	t_gradient;

typedef struct s_mlx_vars
{
	void			*mlx;
	void			*win;
	t_gradient		**coordinates;
	t_cord			*cord;
	t_img			img;
	t_map			*map_;
	int				y;
	int				x;
	int				width_size;
	int				height_size;
	int				y_start;
	int				x_start;
	int				x_end;
	int				y_end;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				z;
	char			**row;
	int				start;
	int				color;
	int				line;
	char			*name;
	int				zoom;
	int				view;
	float			gamma;
	float			tetha;
	float			alpha;
	int				rotate;
}	t_mlx_vars;

typedef struct s_map
{
	char			**line;
	struct s_map	*next;
}	t_map;
////////////////////////////VALIDATION & PARSING////////////////////////////////
int				line_count(char **map);
int				map_len(t_map *map);
void			add_to_map(t_map **map, char *str);
void			init_vars(t_mlx_vars **vars, t_map *map);
t_map			*parser(int fd, t_mlx_vars *vars);
int				is_fdf(char *input, char *str);
void			arguments_check(int ac, char **av);
void			generat2(t_cord *x, t_points *p, t_mlx_vars *v);
void			generat(t_cord *x, t_points *p, t_mlx_vars *v);
char			**ft_split(char const *s, char c);
void			error_handle(char *msg);
int				count_width(char **args);
void			map_generating(t_mlx_vars *vars);
t_coordinates	setting_vars(int x1, int y1, int x2, int y2);
void			do_matrix(t_mlx_vars **vars, t_map *map);
void			first_point(t_points *p, int x, int y, t_mlx_vars *vars);
void			isometric_projection(t_points *p, t_mlx_vars *vars);
/////////////////////////////ROTATING & 3DPART//////////////////////////////////
void			isometric(t_points *p, t_mlx_vars *vars);
void			rotate_x(t_points *p, t_mlx_vars *vars);
void			rotate_y(t_points *p, t_mlx_vars *vars);
void			rotate_z(t_points *p, t_mlx_vars *vars);
void			bresnham(t_mlx_vars *vars, t_coordinates *xy);
int				gradient(int startcolor, int endcolor, \
				int pix, t_mlx_vars *vars);
void			view(int keysym, t_mlx_vars *vars);
void			position(int keysym, t_mlx_vars *vars);
void			zooming(int keysym, t_mlx_vars *vars);
///////////////////////////////UTILS////////////////////////////////////////////
size_t			ft_strlen(const char *str);
void			malloc_check(void *str);
void			free_vars(t_mlx_vars *vars);
void			free_map(t_map *map);
void			free_matrix(t_map *map, t_mlx_vars *vars);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_atoi_base(char *str);
int				ft_atoi(const char *str);
char			*ft_strchr(const char *str, const int c);
int				convert_to_hex(char *str);
void			mlx_side(t_mlx_vars *vars);
t_gradient		*init_row(char **line);
int				line_size(t_mlx_vars *vars);
/////////////////////////////KEY_FUNCTIONS//////////////////////////////////
int				handler(int keysym, t_mlx_vars *vars);
// int	handler(int keysym, t_mlx_vars *vars,t_map *map);
int				mouse_close(t_mlx_vars *vars);


int	zoom(t_mlx_vars *vars);

#endif

#include "fdf.h"

int  line_count(char **map)
{
  int  i;

  i = 0;
  while (map[i])
    i++;
  return (i);
}

int *init_row(char **line)
{
  int	*res;
	int	i;
  int len = line_count(line);

	i = 0;
	res = malloc(sizeof(int) * len);
	malloc_check(res);
	while (line[i])
	{
		res[i] = atoi(line[i]);
		i++;
	}
	return (res);
}
int  map_len(t_map *map)
{
  int  len;

  len = 0;
  while (map)
  {
    len++;
    map = map -> next;
  }
  return (len);
}

void  add_to_map(t_map **map, char *str)
{
  t_map  *new;
  t_map  *temp;

  new = malloc(sizeof(t_map));
  if (!new)
    return ;
  new -> line = ft_split(str);
  new -> next = NULL;
  temp = *map;
  if (!*map)
  {
    *map = new;
  }
  else
  {
    while (temp -> next)
      temp = temp -> next;
    temp -> next = new;
  }
}
void    init_vars(t_mlx_vars **vars, t_map *map)
{
    printf("hello\n");
    (*vars)->height_size=map_len(map);
    (*vars)->width_size = line_count(map -> line);
    printf("len: %d\n", (*vars)->height_size);
    (*vars)->coordinates = malloc(sizeof(int *) * ((*vars)->height_size));
    malloc_check((*vars)->coordinates);
    int i = 0;
    while (i < (*vars)->height_size)
    {
      (*vars)->coordinates[i] = init_row(map -> line);
      map = map -> next;
      i++;
    }
    i = 0;
    printf("Here we are\n");
    while (i < (*vars)->height_size)
    {
      int j = 0;
      while (j < (*vars)->width_size)
        printf("%d   ", (*vars)->coordinates[i][j++]);
      printf("\n");
      i++;
    }
    // vars->coordinates[vars->height_size - 1] = init_row(vars); 
    // vars->coordinates[vars->height_size] = NULL; 
    // vars->mlx = NULL;
    // vars->win = NULL;
    // vars->x = 1500;
    // vars->y = 1000;
    // vars->x_start = 640;
    // vars->y_start = -300;
    // vars->x_end = vars->x - vars->x_start;
    // vars->y_end = vars->y - vars->y_start;
    // vars->dx = vars->x_end - vars->x_start;
    // vars->dy = vars->y_end - vars->y_start;
}

t_coordinates	setting_vars(int x1, int y1, int x2, int y2)
{
	t_coordinates xy;
	
	xy.dx = x2 - x1;
	xy.dy = y2 - y1;
    xy.dx_abs = xy.dx;
    if (xy.dx < 0) 
        xy.dx_abs = -xy.dx;
    xy.dy_abs = xy.dy;
    if (xy.dy < 0) 
        xy.dy_abs = -xy.dy;
    xy.sx = 1;
    if (xy.dx < 0)
        xy.sx = -1;
    xy.sy = 1;
    if (xy.dy < 0) 
        xy.sy = -1;
    xy.x = x1;
    xy.y = y1;
    xy.max = xy.dx_abs;
    xy.min = xy.dy_abs;
    if (xy.dy_abs > xy.dx_abs) 
	{
        xy.max = xy.dy_abs;
        xy.min = xy.dx_abs;
    }
	xy.p = 2 * xy.min - xy.max;
	return(xy);
}

int	is_fdf(char *input, char *str)
{
    int len;
	int	j;

    len  = (ft_strlen(input) - 4);
	if (!input)
		return (1);
	j = 0;
	if(input[len] == 0)
		return (1);
	while (str[j])
	{
		if (input[len] == str[j])
		{
			if(input[len + 1] != str[j + 1])
				return (1);
			j++;
		}

		len++;
    }
	return (0);
}

void    arguments_check(int ac, char **av)
{
    if(ac <= 1)
    {
        write(2, "Please enter the file name!\n", 29);
        exit(EXIT_SUCCESS);
    }
    else if(ac > 2)
    {
        write(2, "Too many arguments!\n", 21);
        exit(EXIT_FAILURE);
    }
    else if (is_fdf(av[1], ".fdf"))
    {
        write(2, "Invalid argument!\n", 19);
        write(2, "Enter a file in <name>.fdf format.\n", 36);
        exit(EXIT_FAILURE);
    }

}

t_map *parser(int fd, t_mlx_vars *vars)
{
    char    *buffer;
    t_map *map;

    vars->height_size = 0;
    vars->width_size = 0;
    while (1)
    {
        buffer = get_next_line(fd);
        if(buffer == 0)
            break ;
        add_to_map(&map, buffer);    
        free(buffer);
    }
    return (map);
}
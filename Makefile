NAME = fdf

SRCS_DIR = sources
INC_DIR = includes
MLX_DIR = minilibx-linux

SRCS = $(wildcard $(SRCS_DIR)/*.c)

OBJS = $(SRCS:.c=.o)

INCLUDE = -I$(INC_DIR) -I$(MLX_DIR)/include
CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror $(INCLUDE) #-g3 -fsanitize=address 
MLXFLAGS = -Lminilibx-linux -lmlx_Linux -lX11 -lXext -lm
# MLXFLAGS = -lmlx -framework OpenGL -framework AppKit 
%.o:	%.c $(INCLUDE) 
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

all: $(NAME)

$(NAME):	$(OBJS) Makefile
	$(CC) $(CFLAGS)  -o $(NAME) $(OBJS) $(MLXFLAGS)

clean:	
	$(RM) $(OBJS) 

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re

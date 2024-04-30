NAME = fdf

SRCS = $(wildcard *.c)

OBJS = $(SRCS:.c=.o)

INCLUDE = -I ./
CC = gcc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror  -g3# -fsanitize=address $(INCLUDE)
#MLXFLAGS = -Lminilibx-linux -lmlx_Linux -lX11 -lXext -lm
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit 
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

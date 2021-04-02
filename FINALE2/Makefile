.PHONY: libft minilibx

SRCS = ./srcs/map.c \
	   ./srcs/main.c \
	   ./srcs/cub3d_utils.c \
	   ./srcs/cub3d_utils2.c \
	   ./srcs/cub3d_utils3.c \
	   ./srcs/init.c \
	   ./srcs/init2.c \
	   ./srcs/parser.c \
	   ./srcs/parser_tex.c \
	   ./srcs/events.c \
	   ./srcs/exit.c \
	   ./srcs/move.c \
	   ./srcs/display.c \
	   ./srcs/ray.c \
	   ./srcs/ray2.c \
	   ./srcs/save.c \
	   ./srcs/save2.c \
	   ./srcs/sprite.c \
	   ./srcs/sprite2.c \
	   ./srcs/sprite3.c \
	   ./srcs/free.c \
	   ./srcs/error.c \
	   ./srcs/error2.c \
	   ./srcs/textures.c \
	   ./gnl/get_next_line.c \
	   ./gnl/get_next_line_utils.c \
		

NAME = Cub3D

GCC_FLAG = -Wall -Werror -Wextra -g
CC = gcc $(GCC_FLAG)

OBJS = $(SRCS:.c=.o)


all: libft minilibx $(NAME)

libft:
	make -C libft/

minilibx:
	make -C minilibx/


$(%.o): $(%.c)
	$(CC) -o $@ -c $^

$(NAME): $(OBJS)
	$(CC) -o $@ $^ -Lminilibx/ -lmlx -framework OPENGL -framework Appkit -Llibft -lft


clean:
	rm -f $(OBJS)
	make -Clibft/ clean
	make -C minilibx/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean
	make -C minilibx/ clean

re: fclean all


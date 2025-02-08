NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX = mlx/libmlx.a

SRC = print.c info.c check_map.c \
get_next_line/get_next_line_utils.c \
get_next_line/get_next_line_utils2.c \
get_next_line/get_next_line_utils3.c \
get_next_line/get_next_line.c \
get_next_line/list.c \
get_next_line/main.c \
check_path.c \
game.c \
create_an_image.c \
destroy.c \
movement.c \
check_map2.c \
help.c \
ft_printf/ft_printf.c \
ft_printf/functions.c \
check_path2.c

MSRC = main.c

OBJ = $(SRC:.c=.o)

MOBJ = $(MSRC:.c=.o)

BONUS = main_b.c

B_OBJ = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(MOBJ) $(MLX)
	$(CC) $(CFLAGS) $^ -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

bonus :	$(OBJ) $(B_OBJ)
	$(CC) $(CFLAGS) $^ -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(MLX):
	make all -C mlx

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	rm -f $(OBJ) $(MOBJ) $(B_OBJ)
	make clean -C mlx


fclean: clean
	rm -f $(NAME)
	make clean -C mlx

re: fclean all
 
.PHONY: all clean fclean re

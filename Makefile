NAME        = so_long

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

LIBFT_DIR   = ./libft
LIBFT       = $(LIBFT_DIR)/libft.a

MLX_DIR     = ./mlx
MLX         = $(MLX_DIR)/libmlx.a
MLX_FLAGS   = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

INCLUDES    = -I./includes -I$(LIBFT_DIR) -I$(MLX_DIR) -I./get_next_line

SRCS        = srcs/main.c \
			  srcs/parse.c\
			  srcs/parse_utils.c\
			  srcs/parse_path.c\
			  srcs/render.c\
              get_next_line/get_next_line.c \
              get_next_line/get_next_line_utils.c
OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(MLX):
	@echo "Using pre-compiled MLX library."

clean:
	@make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

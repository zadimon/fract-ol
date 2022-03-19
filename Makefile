LIBFT_DIR	= ./libft

MLX_DIR		= ./mlx/

LIBFT		= libft.a

NAME		= fractol

BNAME		= fractol_bonus

SRC			= fractol.c\
			ft_init.c\
			ft_color.c\
			ft_mouse_control.c\
			ft_key_control.c\
			ft_formulas.c

OBJ			= $(SRC:.c=.o)

FLAGS		= -Wall -Wextra -Werror -O3

RM			= rm -f

%.o:		%.c fractol.h
			gcc $(FLAGS) -c $< -o $(<:.c=.o)

all:		$(NAME)

bonus:		$(BNAME)

$(NAME):	$(OBJ)
			$(MAKE) -C $(MLX_DIR)
			$(MAKE) bonus -C $(LIBFT_DIR)
			gcc $(FLAGS) -include fractol.h -o $(NAME) $(OBJ) $(LIBFT_DIR)/$(LIBFT) -L ./mlx/ -lmlx -framework OpenGL -framework AppKit

$(BNAME):	$(OBJ)
			$(MAKE) -C $(MLX_DIR)
			$(MAKE) bonus -C $(LIBFT_DIR)
			gcc $(FLAGS) -include fractol.h -o $(BNAME) $(OBJ) $(LIBFT_DIR)/$(LIBFT) -L ./mlx/ -lmlx -framework OpenGL -framework AppKit

clean:
			$(MAKE) clean -C $(MLX_DIR)
			$(MAKE) clean -C $(LIBFT_DIR)
			$(RM) $(OBJ)

fclean:		clean
			$(MAKE) fclean -C $(LIBFT_DIR)
			$(RM) $(NAME) $(BNAME)

re:			fclean all

.PHONY:		all clean fclean re
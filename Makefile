NAME_RT			=	miniRT

INCLUDES_RT		=	includes/
HEADER_RT		=	$(addprefix includes/, \
					draw.h \
					key_def.h \
					minirt.h \
					parser.h \
					)

#LIBFT
DIR_LIB			=	libft/
LIBFT			=	$(DIR_LIB)libft.a

DIR_SRC			=	src/
FILES_SRC		=	main.c \
					print_structs.c \
					free_all.c \
					draw.c \
					vector.c\
					intersect.c\
					intersect_utils.c \
					color.c \
					dist_obj.c \
					shadow.c \
					shadow_intersect.c \
					key_hook.c \
					mouse_hook.c \

DIR_PARSE		=	parser/
FILES_PARSE		=	parser.c \
					validation.c \
					init_parser.c \
					init_parser2.c \
					fill_obj.c \
					fill_scene.c \

SRCS_SRC		=	$(addprefix $(DIR_SRC), $(FILES_SRC))
SRCS_PARSE		=	$(addprefix $(DIR_PARSE), $(FILES_PARSE))
OBJS_SRC		=	$(addprefix objects/, $(FILES_SRC:%.c=%.o) $(FILES_PARSE:%.c=%.o))


CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -g
RM				=	rm -f

#MLX
MLX			= libmlx.a
MLX_PATH	= mlx_1/
MLX_FLAGS	= -framework OpenGL -framework AppKit

.PHONY	:	all clean fclean re libft mlx norm

all		:	mlx libft $(NAME_RT)

mlx:
			@make -C $(MLX_PATH)
			echo "$(OBJS_SRC)"

libft	:
			@make -C $(DIR_LIB)

$(NAME_RT)	:	 $(OBJS_SRC) $(MLX_PATH)$(MLX)
			$(CC) $(OBJS_SRC) $(LIBFT) $(MLX_PATH)$(MLX) $(MLX_FLAGS) -o $@

objects/%.o	:	src/%.c $(LIBFT) $(HEADER_RT) $(MLX_PATH)$(MLX) Makefile
			$(CC) $(CFLAGS) -I $(INCLUDES_RT) -c $< -o $@

objects/%.o	:	parser/%.c $(LIBFT) $(HEADER_RT) $(MLX_PATH)$(MLX) Makefile
			$(CC) $(CFLAGS) -I $(INCLUDES_RT) -c $< -o $@

clean	:
			$(RM)  $(OBJS_SRC)
			make -C $(DIR_LIB) clean

fclean	:	clean
			$(RM) $(NAME_RT)
			make -C $(DIR_LIB) fclean

re		:	fclean all

norm	:
			norminette includes
			norminette libft
			norminette parser
			norminette src

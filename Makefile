NAME = cub3D

SRC_DIR = sources/
INC_DIR = includes/
OBJ_DIR = objects/

INCLUDES = -I$(INC_DIR)

CC = gcc
FLAGS = -g

MLX_DIR = minilibx/
MLX_FLAGS = -L. -lmlx -framework OpenGL -framework AppKit

$(OBJ_DIR):
		@mkdir $(OBJ_DIR)

FILES = cub3d \
		ft_atoi \
		ft_draw_utils \
		ft_get_config \
		ft_init \
		ft_init_text \
		ft_key \
		ft_line_parser \
		ft_lst \
		ft_map \
		ft_mem_manage \
		ft_otherutils \
		ft_raycast \
		ft_render \
		ft_screenshot \
		ft_sprites \
		ft_tex_utils \
		ft_utils \
		ft_validator \
		get_next_line \
		get_next_line_utils \

SRC_FILES = $(addsuffix .c, $(addprefix $(SRC_DIR), $(FILES)))

OBJ_FILES = $(addsuffix .o, $(addprefix $(OBJ_DIR), $(FILES)))

all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJ_FILES)
		@make -C $(MLX_DIR)
		@cp ./minilibx/libmlx.dylib ./
		@$(CC) -o $(NAME) $(INCLUDES) $(OBJ_FILES) $(MLX_FLAGS)

$(OBJ_FILES): $(OBJ_DIR)%.o : $(SRC_DIR)%.c
		@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
		@rm -rf $(OBJ_DIR)
		@rm -f screenshot.bmp
		@echo "All object files have been killed. Maniac!"

fclean: clean
		rm -f $(NAME)
		rm -f libmlx.dylib
		@echo "Now all files and my work have been killed. Why are you bullying me?"

run: re
		@echo "3..."
		@echo "2..."
		@echo "1..."
		./cub3D maps/test.cub

re: fclean all
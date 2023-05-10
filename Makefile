# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wkrippne <wkrippne@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/29 18:30:14 by wkrippne          #+#    #+#              #
#    Updated: 2023/04/09 21:54:34 by wkrippne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= fractol
UNAME_S := $(shell uname -s)
CC		:= cc
CFLAGS	:= -Werror -Wextra -Wall

ifeq ($(UNAME_S), Linux)
	MLX_PATH := minilibx-linux/
	MLX_LNK := -L$(MLX_PATH) -lm -lmlx -lXext -lX11
else ifeq ($(UNAME_S), Darwin)
	MLX_PATH := minilibx-macos/
	MLX_LNK := -L$(MLX_PATH) -lm -lmlx -framework OpenGL -framework AppKit -I$(MLX_PATH)
endif

# Minilibx
MLX			:= $(MLX_PATH)libmlx.a

# Libft
LIBFT_PATH	:= libft/
LIBFT		:= $(LIBFT_PATH)libft.a

# Includes
INC			:=	-I ./includes/\
				-I ./libft/\
				-I $(MLX_PATH)

# Sources
SRC_PATH	:=	src/
SRC			:=	fractol.c \
				initialization.c \
				utils.c \
				events.c \
				render.c \
				color.c \
				parse_args.c \
				help_msg.c \
				fractal_sets/mandelbrot.c \
				fractal_sets/julia.c \
				color_schemes/color_interpolated.c \
				color_schemes/color_special.c \
				color_schemes/color_striped.c
SRCS		= $(addprefix $(SRC_PATH), $(SRC))

# Objects
OBJ_PATH	= obj/
OBJ			= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))

all: $(MLX) $(LIBFT) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJS): $(OBJ_PATH)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)
	@mkdir $(OBJ_PATH)fractal_sets/
	@mkdir $(OBJ_PATH)color_schemes/

$(MLX):
	@make -sC $(MLX_PATH)

$(LIBFT):
	@make -sC $(LIBFT_PATH)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(LIBFT) $(INC) $(MLX_LNK)
	
bonus: all

clean:
	@rm -rf $(OBJ_PATH)
	@make clean -C $(MLX_PATH)
	@make clean -C $(LIBFT_PATH)

fclean: clean
	@rm -f $(NAME)
	@rm -f LIBFT

re: fclean all

.PHONY: all re clean fclean
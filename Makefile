# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/13 14:59:37 by mzaboub           #+#    #+#              #
#    Updated: 2019/12/31 18:36:07 by mzaboub          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fdf

SRC_PATH= src
SRC_NAME= bresenham.c					check_file.c \
		  checkdata_storeit.c			draw_map.c	\
		  freememory.c					hooks_functions.c \
		  main.c						mlxinit.c	\
		  tools.c						transformations.c \
		  bresenham_draw_functions.c	bresenham_help_func.c \
		  tools2.c

HDR_PATH= headers
HDR_NAME= fdf.h

LIB_PATH= libft
LIB= libft.a

OBJ_PATH= obj
OBJ_NAME= $(SRC_NAME:.c=.o)

SRC= $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ= $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
HDR= $(addprefix $(HDR_PATH)/,$(HDR_NAME))

CC= gcc
CFLAGES= -Wall -Wextra -Werror
HDR_FLAGS= -I.

LD_FLAGS= -L$(LIB_PATH)
FRAMEWORK_FLAGS=  -lmlx -framework OpenGL -framework AppKit
LD_LIBS= -l$(patsubst lib%.a,%, $(LIB))


# **************************************************************************** #

all:$(NAME)

$(NAME): $(LIB_PATH)/$(LIB) $(OBJ)
	@$(CC) $(LD_FLAGS) $(FRAMEWORK_FLAGS) $(LD_LIBS) $(OBJ) -o $@
	@echo "FDF: executable file is ready ;)"	########## modify this

$(LIB_PATH)/$(LIB):
	@make -C libft

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HDR)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(HDR_FLAGS) -o $@ -c $<

clean:
	@rm -fr $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@make -C libft clean
	@echo "FDF: object files deleted"

fclean: clean
	@rm -fr $(NAME)
	@make -C libft fclean
	@echo "FDF: all resources deleted"

re: fclean all

NAME= fdf

SRC_PATH= .
SRC_NAME= bresenham.c	check_file.c		checkdata_storeit.c	draw_map.c	\
		  freemap.c		hooks_functions.c	main.c	mlxinit.c		tools.c	\
		  transformations.c bresenham_draw_functions.c	bresenham_help_func.c \
		  tools2.c
SRC= $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ_PATH= obj
OBJ_NAME= $(SRC_NAME:.c=.o)
OBJ= $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

LIB_PATH= libft
LIB= libft.a

# ***************************************** #
# Dont tuch thi code under this				#
# exept what I told you so in the comments	#
# ***************************************** #

CC= gcc
CFLAGES= -Wall -Wextra -Werror

LD_FLAGS= -L$(LIB_PATH)
FRAMEWORK_FLAGS=  -lmlx -framework OpenGL -framework AppKit 
LD_LIBS= -l$(patsubst lib%.a,%, $(LIB))
HDR_FLAGS= -I. 

all:$(NAME)

$(NAME): $(LIB_PATH)/$(LIB) $(OBJ)
	@$(CC) $(LD_FLAGS) $(FRAMEWORK_FLAGS) $(LD_LIBS) $(OBJ) -o $@
	@echo "FDF: executable file is ready ;)" 	########## modify this

$(LIB_PATH)/$(LIB):
	@make -C libft

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(HDR_FLAGS) -o $@ -c $<

clean:
	@rm -fr $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@make -C libft clean
	@echo "FDF: object files deleted" 			########## modify this

fclean: clean
	@rm -fr $(NAME)
	@make -C libft fclean
	@echo "FDF: all resources deleted" 			########## modify this

re: fclean all

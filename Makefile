.PHONY: clean $(NAME) fclean re all

NAME	= wolf3d

SRC		 =		srcs/calc.c				\
				srcs/main.c				\
				srcs/hooks.c			\
				srcs/init.c				\
				srcs/move.c				\
				srcs/read.c				\
				srcs/mamba.c	

OBJ		= $(patsubst src/%.c,obj/%.o,$(SRC))

all: $(NAME)

$(NAME): $(OBJ) includes/wolf3d.h
		make -C libft/
		gcc -Wall -Wextra -Werror -L libft/ -lft -g -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit $(SRC) -o $(NAME)

obj/%.o: src/%.c
		mkdir -p obj
		gcc -Wall -Wextra -Werror -c $< -o $@

clean:
		/bin/rm -rf obj/
		make -C libft/ clean

fclean: clean
		/bin/rm -f $(NAME)
		make -C libft/ fclean

re: fclean all

test: re
		./$(NAME)

all: $(NAME)

NAME = wolf3d

CC = gcc -Wall -Werror -Wextra -L/usr/X11/lib -lmlx -lXext -lX11 -I /usr/X11/include -I /usr/include -Ofast -o3

SRC =	./src/mlx.c\
		./src/ft_init.c\
		./src/ft_key.c\
		./src/wolf3d.c\
		./src/main.c\
		./src/ft_init2.c\
		./src/ft_init3.c\
		./src/labyrinthe_algo.c\
		./src/labyrinthe_algo2.c\
		./src/labyrinthe_algo3.c\
		./src/wolf_weapon.c

COMPILE = echo "\033[36mCompile --wolf3d-- ...."
COMPILED = echo "\033[32mCompiled --wolf3d-- Successfully"
CLEAN = echo "\033[36mClean --wolf3d-- ...."
CLEANED = echo "\033[32mCleaned --wolf3d-- Successfully"

all: $(NAME)

$(NAME):
	@$(COMPILE)
	@make -C ./libft re
	@$(CC) -o $(NAME) $(SRC) ./libft/libft.a 
	@$(COMPILED)

norme:
	@norminette $(SRC) ./src/wolf3d.h
	@make -C ./libft norme
rego: re
	@./$(NAME)

clean:
	@$(CLEAN)
	@make -C ./libft clean
	@$(CLEANED)

fclean: clean
	@make -C ./libft fclean
	@rm -f $(NAME)

re : fclean all
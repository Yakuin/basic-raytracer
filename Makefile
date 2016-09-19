NAME =	rtv1

SRC =	raytracer.c \
	vect_op.c \
	ray_collide.c \
	init.c

OBJ =	$(SRC:.c=.o)

# Uncomment and add any flags and library if needed
# LIB = 

FLG = -Wextra -Wall -Werror

$(NAME): $(OBJ)
	@echo "Compiling..."
	@gcc -c $(FLG) $(SRC)
	@gcc -o $(NAME) $(OBJ) $(LIB)
	@echo "Done !"

all: $(NAME)

clean:
	@echo "Deleting object files..."
	@rm -f $(OBJ)
	@echo "Done !"

fclean: clean
	@echo "Deleting executable..."
	@rm -f $(NAME)
	@echo "Done !"

re: fclean all

.PHONY: all clean fclean re
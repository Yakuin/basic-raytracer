#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yboualla <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/20 14:57:09 by yboualla          #+#    #+#              #
#    Updated: 2016/10/31 06:03:31 by yboualla         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =	rtv1

SRC =	raytracer.c \
		vect_op.c \
		ray_collide.c \
		init.c \
		events.c \
		overlay.c \
		draw.c \
		parser.c

OBJ =	$(SRC:.c=.o)

LIB =	-Llibft/ -lft -lmlx -framework AppKit -framework OpenGL

FLG =	-Wextra -Wall -Werror

$(NAME): $(OBJ)
	@echo "\x1B[32mCompiling libft..."
	@make -C "libft/"
	@echo "Compiling basic raytracer..."
	@gcc -c -Ofast $(FLG) $(SRC)
	@gcc -g -o $(NAME) $(OBJ) $(LIB)
	@echo "\x1B[37;1mDone !"
	@echo "\x1B[37m"

all: $(NAME)

clean:
	@echo "\x1B[32;1mDeleting object files..."
	@make -C "libft/" clean
	@rm -f $(OBJ)
	@echo "\x1B[37;1mDone !"
	@echo "\x1B[37m"

fclean: clean
	@echo "Deleting executable..."
	@make -C "libft/" fclean
	@rm -f $(NAME)
	@echo "\x1B[37;1mDone !"
	@echo "\x1B[37m"

re: fclean all

.PHONY: all clean fclean re
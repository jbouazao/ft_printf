# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbouazao <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/25 10:02:55 by jbouazao          #+#    #+#              #
#    Updated: 2019/06/26 12:06:52 by jbouazao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra

SRC = srcs/*.c ft_printf.c

OBJ = *.o

LIBFT = libft/*.o

all: $(NAME)

$(NAME) :
			make -C libft
			gcc -I ft_printf.h $(FLAGS) -c $(SRC)
			ar rc $(NAME) $(OBJ) $(LIBFT)
			gcc $(NAME)
clean:
			make clean -C libft
			/bin/rm -f $(OBJ)
fclean: clean
			make fclean -C libft
			/bin/rm -f $(OBJ) $(NAME)
re: fclean all

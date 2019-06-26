# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbouazao <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/25 10:02:55 by jbouazao          #+#    #+#              #
#    Updated: 2019/06/26 09:45:18 by jbouazao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra

SRC = srcs/c_conv.c srcs/spc_perc_strct.c srcs/s_conv.c ft_printf.c

OBJ = c_conv.o spc_perc_strct.o s_conv.o ft_printf.o

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

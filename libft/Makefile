# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbouazao <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/25 23:25:07 by jbouazao          #+#    #+#              #
#    Updated: 2018/11/25 23:25:17 by jbouazao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
		@gcc $(FLAG) -c *.c
			@ar rc $(NAME) *.o

clean:
		@/bin/rm -f *.o

fclean: clean
		@/bin/rm -f $(NAME)

re: fclean all

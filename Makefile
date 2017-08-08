# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acolas <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/08 17:14:08 by acolas            #+#    #+#              #
#    Updated: 2017/08/08 17:16:13 by acolas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ll: test_gnl

test_gnl : main.c get_next_line.c
	make -C libft/ fclean && make -C libft/
	clang -Wall -Wextra -Werror -g -I libft/includes -o get_next_line.o -c get_next_line.c
	clang -Wall -Wextra -Werror -g -I libft/includes -o main.o -c main.c
	clang -g -o test_gnl main.o get_next_line.o -I libft/includes -L libft -lft
	clang -g -o test_gnl1 main1.o get_next_line.o -I libft/includes -L libft -lft

.PHONY: clean fclean

clean:
	make -C libft/ clean
	rm -f main.o get_next_line.o

fclean: clean
	make -C libft/ fclean
	rm -f test_gnl

re: fclean all

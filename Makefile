# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/16 14:07:05 by sdummett          #+#    #+#              #
#    Updated: 2022/06/16 14:25:04 by sdummett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				= clang++
CFLAGS			= -Wall -Wextra -Werror -std=c++98
NAME			= ft_containers

VECTOR_SRCS		= srcs/main_vector.cpp
STACK_SRCS		= srcs/main_stack.cpp
MAP_SRCS		= srcs/main_map.cpp
SET_SRCS		= srcs/main_set.cpp

DEF_FT			= -DFT

RMRF			= rm -rf


all: vector stack map set

vector:
	$(CC) $(VECTOR_SRCS) $(DEF_FT) -o vector_ft_test
	$(CC) $(VECTOR_SRCS)      -o vector_std_test
	./vector_ft_test > vector_ft_test.log
	./vector_std_test > vector_std_test.log
	diff vector_ft_test.log vector_std_test.log > vector_test.diff; true

stack:
	$(CC) $(STACK_SRCS) $(DEF_FT) -o stack_ft_test
	$(CC) $(STACK_SRCS)      -o stack_std_test
	./stack_ft_test > stack_ft_test.log
	./stack_std_test > stack_std_test.log
	diff stack_ft_test.log stack_std_test.log > stack_test.diff; true

map:
	$(CC) $(MAP_SRCS) $(DEF_FT) -o map_ft_test
	$(CC) $(MAP_SRCS)      -o map_std_test
	./map_ft_test > map_ft_test.log
	./map_std_test > map_std_test.log
	diff map_ft_test.log map_std_test.log > map_test.diff; true

set:
	$(CC) $(SET_SRCS) $(DEF_FT) -o set_ft_test
	$(CC) $(SET_SRCS)      -o set_std_test
	./set_ft_test > set_ft_test.log
	./set_std_test > set_std_test.log
	diff set_ft_test.log set_std_test.log > set_test.diff; true

clean:
	$(RMRF) vector_ft_test vector_std_test \
			stack_ft_test stack_std_test \
			map_ft_test map_std_test \
			set_ft_test set_std_test \
			vector_ft_test.log \
			vector_std_test.log \
			stack_ft_test.log \
			stack_std_test.log \
			map_ft_test.log \
			map_std_test.log \
			set_ft_test.log \
			set_std_test.log \
			vector_test.diff \
			stack_test.diff \
			map_test.diff \
			set_test.diff

fclean: clean

re: fclean all
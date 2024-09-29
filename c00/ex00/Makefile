# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkaztaou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/02 17:47:57 by bkaztaou          #+#    #+#              #
#    Updated: 2024/01/02 17:54:36 by bkaztaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=megaphone
CXX=clang++
CXXFLAGS=-Wall -Wextra -Werror -std=c++98

SRC= megaphone.cpp
OBJ= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

.PHONY: all clean fclean
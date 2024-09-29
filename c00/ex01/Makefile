# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkaztaou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/02 17:57:03 by bkaztaou          #+#    #+#              #
#    Updated: 2024/01/16 21:18:36 by bkaztaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=phonebook
CXX=clang++
CXXFLAGS=-Wall -Wextra -Werror -std=c++98

SRC= PhoneBook.cpp Contact.cpp main.cpp
OBJ= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean
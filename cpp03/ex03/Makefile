# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/15 07:05:49 by mbendidi          #+#    #+#              #
#    Updated: 2025/07/15 14:28:33 by mbendidi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = diamondtrap

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -Wshadow -Wno-shadow -std=c++98
DBGFLAGS = -g -std=c++98

SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

debug:
		$(CXX) $(DBGFLAGS) $(SRCS) -o $(NAME)

valgrind: debug
		valgrind ./$(NAME)

.PHONY: all clean fclean re

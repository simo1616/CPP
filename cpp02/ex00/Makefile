# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/12 20:48:06 by mbendidi          #+#    #+#              #
#    Updated: 2025/07/13 12:53:57 by mbendidi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fixed

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
DBGFLAGS = -g -std=c++98

SRCS = main.cpp Fixed.cpp

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
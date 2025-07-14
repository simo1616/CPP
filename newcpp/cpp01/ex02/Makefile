# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/11 16:30:51 by mbendidi          #+#    #+#              #
#    Updated: 2025/07/11 20:16:19 by mbendidi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = brain

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
DBGFLAGS = -g -std=c++98

SRCS = main.cpp
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

.PHONY: all clean fclean re debug valgrind

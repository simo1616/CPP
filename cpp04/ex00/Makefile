NAME = poly

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -Wshadow -Wno-shadow -std=c++98
DBGFLAGS = -g -std=c++98

SRCS = main.cpp Animal.cpp Dog.cpp Cat.cpp \
		WrongAnimal.cpp WrongCat.cpp

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
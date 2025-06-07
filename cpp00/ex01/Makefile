NAME    = phonebook

CXX     = c++
CXXFLAGS= -std=c++98 -Wall -Werror -Wextra

SRCS    = main.cpp \
          PhoneBook.cpp \
          Contact.cpp

OBJS    = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

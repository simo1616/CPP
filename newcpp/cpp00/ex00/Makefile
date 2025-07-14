
NAME = megaphone

CXX = c++ 
CXXFLAGS = -std=c++98 -Wall -Werror -Wextra

SRCS = Megaphone.cpp
OBJS = $(SRCS:.cpp=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(NAME) $(OBJS)

.PHONY: all clean fclean re
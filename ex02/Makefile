NAME = forms
CC = c++
HEADER = AForm.hpp \
		Bureaucrat.hpp \
		ShrubberyCreationForm.hpp
FLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = AForm.cpp \
		Bureaucrat.cpp \
		ShrubberyCreationForm.cpp \
		main.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

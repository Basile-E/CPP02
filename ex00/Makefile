NAME = Vatican

CC = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror

SRC = main.cpp Fixed.cpp
OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean :
	rm -f *.o

fclean : clean
	rm -f $(NAME);

re : fclean
	$(MAKE) all
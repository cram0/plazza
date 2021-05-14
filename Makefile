##
## EPITECH PROJECT, 2021
## B-CCP-400-NCE-4-1-theplazza-julien.augugliaro
## File description:
## Makefile
##

NAME        =       plazza

SRC         =       $(shell find . -name '*.cpp')

OBJ         =       $(SRC:.cpp=.o)

CXXFLAGS    +=      -Wall
CXXFLAGS    +=      -Wextra
CXXFLAGS    +=      -Wno-unused-parameter
CXXFLAGS    +=      -I./include

all         :       $(NAME)

$(NAME)     :       $(OBJ)
					g++ $(CXXFLAGS) -o $(NAME) $(OBJ) -g3 -O0 -lpthread

clean       :
					find . -name "*.o" -type f -delete
					find . -name "vgcore.*" -type f -delete

fclean      :       clean
					rm -f $(NAME)

re          :       fclean all
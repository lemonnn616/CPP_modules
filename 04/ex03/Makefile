NAME = materia

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++11

SRC = main.cpp \
		AMateria.cpp Character.cpp MateriaSource.cpp \
		Ice.cpp Cure.cpp

HDR = AMateria.hpp ICharacter.hpp Character.hpp \
		IMateriaSource.hpp MateriaSource.hpp \
		Ice.hpp Cure.hpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(HDR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

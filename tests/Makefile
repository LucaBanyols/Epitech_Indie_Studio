##
## EPITECH PROJECT, 2021
## indie
## File description:
## test_Makefile
##

SRC	=	../src/Game/Map.cpp

UT_SRC	=	cr_test_error_handling.cpp

OBJ	=	$(SRC:.c=.o)	\
		$(UT_SRC:.c=.o)

RM	=	rm -f

LDFLAGS	=	-lcriterion -lgcov -lpthread

CPPFLAGS	=	-I ../include

NAME	=	unit_tests

all:	$(NAME)

$(NAME):	$(OBJ)
	-g++ -o $(NAME) $(OBJ) $(LDFLAGS)
	./$(NAME)

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)
	$(RM) *.gcda
	$(RM) *.gcno
	$(RM) *~

re:	fclean all

.PHONY: all clean fclean re

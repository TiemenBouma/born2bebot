NAME	=	born2bebot
CFLAGS	=	-Wall -Wextra -Werror -pedantic $(WNO) $(SANI)
SANI	=	-fsanitize=address -g
WNO		=	-Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-unused-private-field

IDIR	=	inc
SDIR	=	src

_SRC	=	main utils timer bot input init logic free

SRC		=	$(addsuffix .c, $(addprefix $(SDIR)/, $(_SRC)))

ifeq ($(shell uname -s),Linux)
	CFLAGS += -lbsd -pthread -lm
endif

all:
	$(CC) -I$(IDIR) -o $(NAME) $(SRC) $(CFLAGS)

fclean:
	rm -rf $(NAME)

re: fclean all

test: all
	clear
	./$(NAME)

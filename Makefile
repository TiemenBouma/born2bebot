NAME	=	born2bebot
CFLAGS	=	-Wall -Wextra -Werror -pedantic $(WNO)
WNO		=	-Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-unused-private-field

IDIR	=	inc
SDIR	=	src

_SRC	=	main utils timer bot input init logic

SRC		=	$(addsuffix .c, $(addprefix $(SDIR)/, $(_SRC)))

all:
	$(CC) $(CFLAGS) $(SRC) -I$(IDIR) -o $(NAME)

fclean:
	rm -rf $(NAME)

re: fclean all

test: all
	clear
	./$(NAME)

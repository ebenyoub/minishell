NAME		=	mini
CC			=	CC
CFLAGS		=	-Wall -Wextra -Werror -g3 -ggdb -fsanitize=address 
SRCS		=	$(wildcard *.c)
OBJ			=	$(SRCS:.c=.o)

all: $(NAME)


$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

%.o: %.c %.h
	$(CC) -c $(CFLAGS) -o $@

clean: 
	rm $(OBJ)

fclean:
	rm $(OBJ)
	rm $(NAME)

re: fclean all

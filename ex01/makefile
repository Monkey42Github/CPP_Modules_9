NAME = RPN

.PHONY: all, fclean, re

SRCS = main.cpp RPN.cpp

OBJS = $(SRCS:.c=.o)

CC = c++

CFLAGS = -Wall -Wextra -Werror #-std=c++98

all: $(NAME)

$(NAME):$(SRCS)
		$(CC) $(CFLAGS) $(SRCS) -o $(NAME)


fclean:
		rm -f $(NAME)

re: fclean all


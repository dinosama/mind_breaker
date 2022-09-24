NAME = mind_breaker

SRCS = 

OBJS = $(subst .cpp,.o,$(SRCS))

CC = g++

CFLAGS = -Wall -Wextra -Werror -std=c++98

RM = /bin/rm -rf

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
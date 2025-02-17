SRCS = $(wildcard *.c) \
       $(wildcard utils/*.c) \
       $(wildcard utils/ft_printf/*.c) \
	   $(wildcard moves/*.c) \
	   $(wildcard algorithm/*.c)
	   
        

OBJS := $(SRCS:.c=.o)

CC := gcc
FLAGS := -Wall -Werror -Wextra

NAME := push_swap

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) 

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all

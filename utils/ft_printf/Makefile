SRCS =  ft_printf.c\
		ft_printf_utils.c\
        

OBJS := $(SRCS:.c=.o)

CC := gcc
FLAGS := -Wall -Werror -Wextra

NAME := libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all

SRCS =  push_swap.c\
		utils/ft_atoi.c\
		utils/ft_split.c\
		utils/ft_strjoin.c\
		utils/ft_printf/ft_printf.c\
		utils/ft_printf/ft_printf_utils.c\
        

OBJS := $(SRCS:.c=.o)

CC := gcc
FLAGS := -Wall -Werror -Wextra

NAME := push_swap.a

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

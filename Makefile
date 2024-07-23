CC = cc

CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address

SRCS =  main.c clear.c identifier.c ft_lstadd_back.c \
		ft_lstnew.c ft_atoi.c ft_split.c \
		check_list.c ft_strlen.c ft_substr.c \
		sorting.c ft_lstsize.c ft_lstlast.c get_position.c \
		sort_with_butterfly.c push.c rotate.c rerotate.c swap.c

B_SRCS = checker.c get_next_line.c get_next_line_utils.c \
	     swap.c push.c rotate.c rerotate.c ft_atoi.c \
		 ft_putstr_fd.c ft_putchar_fd.c ft_split.c \
		 clear.c ft_lstsize.c ft_lstlast.c ft_lstnew.c \
		 ft_lstadd_back.c identifier.c check_list.c ft_substr.c \
		 ft_strlen.c 

INCS = push_swap.h

NAME = push_swap

B_NAME = checker

OBJS = $(SRCS:.c=.o)

B_OBJS = $(B_SRCS:.c=.o)

all: $(NAME)

bonus: $(B_NAME)

$(NAME): $(OBJS) 
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(B_NAME): $(B_OBJS)
	$(CC) $(CFLAGS) $(B_OBJS) -o $(B_NAME)

%.o: %.c Makefile ####### AVELACNEL HEADER
	$(CC) $(CFLAGS) -c $< -o $@

re: fclean all

clean:
	rm -f $(OBJS) $(B_OBJS)

fclean: clean
	rm -f $(NAME) $(B_NAME)

.PHONY: all re clean fclean
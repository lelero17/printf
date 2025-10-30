NAME	= printf.a

CC		= cc
CFLAGS	+= -Wall -Wextra -Werror

AR		= ar 
ARFLAGS = rcs

RM		= rm -f

SRCS	= 	ft_printf.c

OBJS	= $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
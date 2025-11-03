NAME        = libftprintf.a

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

AR          = ar
ARFLAGS     = rcs

RM          = rm -f

SRCS        =  ft_printf.c \
               ft_conv.c \
               ft_print_char.c \
               ft_print_str.c \
               ft_print_nbr.c \
               ft_print_hex.c \
               ft_print_vptr.c

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
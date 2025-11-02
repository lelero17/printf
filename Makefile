NAME        = libftprintf.a

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

AR          = ar
ARFLAGS     = rcs

RM          = rm -f

LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a

SRCS        =  ft_printf.c \
               ft_conv.c \
               ft_print_char.c \
               ft_print_str.c \
               ft_print_nbr.c \
               ft_print_hex.c \
               ft_print_vptr.c

OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -I./libft -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
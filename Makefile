NAME		= libftprintf.a
LIBFT		= libft
LIBFT_LIB	= libft.a

SRCS					= ft_printf.c \
					  ft_printf_util.c \
					  ft_printf_c%.c \
					  ft_printf_diu.c \
					  ft_printf_diu_util.c \
					  ft_printf_xX.c \
					  ft_printf_xX_util.c \
					  ft_printf_s.c

BNS_SRCS				= ft_printf_bonus.c \
					  ft_printf_util_bonus.c \
					  ft_printf_c%_bonus.c \
					  ft_printf_diu_bonus.c \
					  ft_printf_diu_util_bonus.c \
					  ft_printf_xX_bonus.c \
					  ft_printf_xX_util_bonus.c \
					  ft_printf_s_bonus.c

OBJS					= $(SRCS:%.c=%.o)

BNS_OBJS				= $(BNS_SRCS:%.c=%.o)

LIBC		= ar rc

FLAGS					= -Wall -Wextra -Werror

ifdef WITH_BONUS
	OBJ_FILES = $(OBJS) $(BNS_OBJS)
else
	OBJ_FILES = $(OBJS)
endif

all	:	$(NAME)

$(NAME) : $(OBJ_FILES)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	$(LIBC) $(NAME) $(OBJ_FILES)

%.o			: %.c
	gcc $(FLAGS) -c $^ -I./ -o $@

bonus :
	make WITH_BONUS=1 all

clean	:
		rm -f $(OBJS) $(BNS_OBJS)
		make clean -C $(LIBFT)

fclean	:	clean
		rm -f $(NAME)
		rm -f $(LIBFT_LIB)
		make fclean -C $(LIBFT)

re	:	fclean all

.PHONY	:	all clean fclean re bonus

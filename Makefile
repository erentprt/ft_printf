NAME	= libftprintf.a
RM		= rm -f

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

LIB1	= ar -rcs
LIB2	= ranlib

SRCS_MAND	=	ft_num_utils.c \
				ft_str_utils.c \
				ft_printf.c \

OBJS_MAND	=	${SRCS_MAND:.c=.o}

$(NAME)	:	$(OBJS_MAND)
			$(LIB1) $(NAME) $(OBJS_MAND)
			$(LIB2) $(NAME)

all		:	$(NAME)

%.o		:	%.c
			$(CC) $(CFLAGS) -c $< -o $@

clean	:	
			$(RM) $(OBJS_MAND)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
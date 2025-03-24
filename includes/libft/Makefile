NAME	=	libft.a
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
AR		=	ar
ARFLAGS	=	-rcs
SRCS	=	

OBJS	=	$(SRCS:%.c=%.o)

RM		= rm -f

all: $(NAME) clean

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
NAME	=	gnl.a
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
AR		=	ar
ARFLAGS	=	-rcs
SRCS	=	get_next_line.c get_next_line_utils.c

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
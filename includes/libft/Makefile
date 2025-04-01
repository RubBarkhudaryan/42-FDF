NAME			= libft.a
CC				= cc
CFLAGS			= -Wall -Wextra -Werror
AR				= ar
ARFLAGS			= -rcs
SRCS			= ft_isdigit.c ft_strlcpy.c ft_strcmp.c ft_atoi.c ft_split.c ft_calloc.c

OBJS			= $(SRCS:%.c=%.o)

RM				= rm -f

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re 
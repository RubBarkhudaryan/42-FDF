NAME		= fdf
ARCHIVE		= fdf_lib.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

AR			= ar
ARFLAGS		= -rcs

MLXFLAGS	= -Lmlx -lmlx -lX11 -lXext -lm

SRCS		= fdf_utils.c fdf_map_validator.c
OBJS		= $(SRCS:%.c=%.o)

RM			= rm -rf

all : $(ARCHIVE) $(NAME)

$(ARCHIVE) : $(OBJS)
	make -C ./includes/gnl
	make -C ./includes/libft

	$(AR) x ./includes/gnl/gnl.a
	$(AR) x ./includes/libft/libft.a

	$(AR) $(ARFLAGS) $(ARCHIVE) $(OBJS) get_next_line.o get_next_line_utils.o \
	ft_isdigit.o ft_strlcpy.o ft_strcmp.o ft_atoi.o ft_split.o

	rm -f get_next_line.o get_next_line_utils.o \
	ft_isdigit.o ft_strlcpy.o ft_strcmp.o ft_atoi.o ft_split.o

	make -C ./includes/gnl clean
	make -C ./includes/libft clean

$(NAME):
	$(CC) $(CFLAGS) parser.c $(ARCHIVE) $(MLXFLAGS) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME) $(ARCHIVE)

re: fclean all

.PHONY: all clean fclean re
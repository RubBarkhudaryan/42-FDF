NAME		= fdf
ARCHIVE		= fdf_lib.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

AR			= ar
ARFLAGS		= -rcs

MLXFLAGS	= -Lmlx -lmlx -lX11 -lXext -lm

SRCS		= fdf_mlx_utils.c fdf_map_validator.c fdf_libft.c ft_split.c
OBJS		= $(SRCS:%.c=%.o)

RM			= rm -rf

all :  $(ARCHIVE) $(NAME)

$(ARCHIVE) : $(OBJS)
	make -C ./includes/gnl
	cp ./includes/gnl/gnl.a $(ARCHIVE)
	make -C ./includes/gnl clean
	$(AR) $(ARFLAGS) $(ARCHIVE) $(OBJS)

$(NAME):
	$(CC) $(CFLAGS) fdf_main.c $(ARCHIVE) $(MLXFLAGS) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME) $(ARCHIVE)

re: fclean all

.PHONY: all clean fclean re
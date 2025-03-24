TARGET		= fdf
ARCHIVE		= fdf.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
MLXFLAGS	= -Lmlx -lmlx -lX11 -lXext -lm
SRCS		= fdf.c fdf_utils.c

OBJS		= $(SRCS:%.c=%.o)
RM			= rm -rf

all : $(TARGET)

$(ARCHIVE) :
	make -C ./includes/gnl
	cp 
	make -C ./includes/gnl clean

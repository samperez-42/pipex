NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror
#-fsanitize=address
RM = rm -rf

LIBFT_PATH = includes/libft
LIBFT = $(LIBFT_PATH)/libft.a

HEADERS = -I ./includes -I $(LIBFT_PATH)

SRCS =	./src/main.c \

SRCDIR = src/
OBJS = $(SRCS:$(SRCDIR)%.c=%.o)

all : $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(HEADERS) -o $(NAME) -lm

%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_PATH)

clean:
	make -C $(LIBFT_PATH) clean

fclean:
	$(RM) $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all
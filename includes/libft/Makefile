CC = cc
CFLAGS = -Werror -Wall -Wextra

SRC = 	ft_isalpha.c \
		ft_bzero.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_strlen.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strncmp.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_substr.c \
		ft_strrchr.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_split.c \
		ft_itoa.c \
		ft_striteri.c \
		ft_strmapi.c \
		ft_strtrim.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_calloc.c \
		get_next_line_utils.c \
		get_next_line.c \
		ft_printf.c \
		ft_printf_utils.c \
		ft_lstnew_bonus.c \
		ft_lstadd_front_bonus.c \
		ft_lstsize_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstiter_bonus.c \
		ft_lstmap_bonus.c 

OBJ = $(SRC:.c=.o)

NAME = libft.a
LIB = libft.h

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "Libft compiled!"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

run:
	$(CC) test.c $(CFLAGS) -lft -L.
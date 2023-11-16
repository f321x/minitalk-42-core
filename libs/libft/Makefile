CC = cc
CFLAGS = -Wall -Wextra -Werror -I./includes
DFLAGS = -g
NAME = libft.a
SRCS = ft_putstr_fd.c ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
BONUS = ft_lstnew.c ft_lstadd_back.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS:.c=.o)

DEBUG_OBJS = ${SRCS:.c=.d.o}
DEBUG_BONUS_OBJS = ${BONUS:.c=.d.o}

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.d.o: %.c
	$(CC) $(CFLAGS) $(DFLAGS) -c $< -o $@

$(NAME): $(SRCS) $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: all $(BONUS_OBJS)
	ar rcs $(NAME) $(BONUS_OBJS)

debug: $(DEBUG_OBJS) $(DEBUG_BONUS_OBJS)
	ar rcs $(NAME) $(DEBUG_OBJS) $(DEBUG_BONUS_OBJS)

clean:
	rm -f $(OBJS) $(BONUS_OBJS) $(DEBUG_BONUS_OBJS) $(DEBUG_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

NAME ?= libft.a
CFLAGS = -Wall -Wextra -Werror
SRCS = \
	ft_atoi.c		ft_isalnum.c	ft_isdigit.c	ft_memcmp.c		ft_memset.c		ft_strlcat.c	ft_strncmp.c	ft_tolower.c	\
	ft_bzero.c		ft_isalpha.c	ft_isprint.c	ft_memcpy.c		ft_strchr.c		ft_strlcpy.c	ft_strnstr.c	ft_toupper.c	\
	ft_calloc.c		ft_isascii.c	ft_memchr.c		ft_memmove.c	ft_strdup.c		ft_strlen.c		ft_strrchr.c	ft_substr.c		\
	ft_strjoin.c	ft_strtrim.c	ft_split.c		ft_itoa.c		ft_strmapi.c	ft_striteri.c	ft_putchar_fd.c	ft_putstr_fd.c	\
	ft_putendl_fd.c	ft_putnbr_fd.c	ft_printf/ft_printf.c			ft_printf/ft_printers.c			ft_err.c		ft_warn.c		
BONUS_SRCS = \
	ft_lstnew_bonus.c		ft_lstadd_front_bonus.c	ft_lstsize_bonus.c	ft_lstlast_bonus.c	\
	ft_lstadd_back_bonus.c	ft_lstdelone_bonus.c	ft_lstclear_bonus.c	ft_lstiter_bonus.c	\
	ft_lstmap_bonus.c
OBJS = ${SRCS:.c=.o}
BONUS_OBJS = ${BONUS_SRCS:.c=.o}

all: ${NAME}

fclean: clean
	rm -f ${NAME}

clean: 
	rm -f ${OBJS} ${BONUS_OBJS}

re: fclean all

${NAME}: ${OBJS}
	ar rc ${NAME} ${OBJS}

bonus: ${BONUS_OBJS} ${NAME}
	ar rc ${NAME} ${BONUS_OBJS}

%.o: %.c
	gcc ${CFLAGS} -o ${@} -c ${@:.o=.c}

.PHONY: re clean fclean all
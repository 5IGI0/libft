NAME ?= libft.a
CFLAGS = -Wall -Wextra -Werror
SRCS = $(addsuffix .c, \
		$(addprefix src/fds/, ft_putchar_fd ft_putendl_fd ft_putnbr_fd ft_putstr_fd)\
		$(addprefix src/other/, ft_err ft_warn)\
		$(addprefix src/memory/, ft_calloc ft_memchr ft_memcpy ft_memcmp ft_memset ft_memmove ft_bzero)\
		$(addprefix src/strings/, ft_atoi ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint ft_itoa ft_startswith ft_strchrnul)\
		$(addprefix src/strings/, ft_split ft_strchr ft_strdup ft_striteri ft_strjoin ft_strlcat ft_strlcpy ft_endswith ft_isspace)\
		$(addprefix src/strings/, ft_strlen ft_strmapi ft_strncmp ft_strnstr ft_strrchr ft_strtrim ft_substr ft_toupper ft_tolower)\
		$(addprefix ft_printf/, ft_printf ft_printers)\
	)
BONUS_SRCS = $(addsuffix .c, $(addprefix src/linked_list/, ft_lstadd_front ft_lstadd_back ft_lstdelone ft_lstiter ft_lstmap ft_lstnew ft_lstlast ft_lstsize ft_lstclear))
OBJS = ${SRCS:.c=.o}
BONUS_OBJS = ${BONUS_SRCS:.c=.o}

all: ${NAME}

fclean: clean
	rm -f ${NAME}

clean: 
	rm -f ${OBJS} ${BONUS_OBJS}

re: fclean all

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

bonus: ${BONUS_OBJS} ${NAME}
	ar rcs ${NAME} ${BONUS_OBJS}

%.o: %.c
	gcc ${CFLAGS} -o ${@} -c ${@:.o=.c}

.PHONY: re clean fclean all
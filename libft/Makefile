
NAME = libft.a

CC = gcc

CFLAGS = -Werror -Wextra -Wall

SRCS = ft_strncmp.c get_next_line_utils.c get_next_line.c ft_strlcat.c ft_calloc.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c ft_split.c ft_strtrim.c ft_strjoin.c ft_strmapi.c ft_substr.c ft_striteri.c ft_bzero.c  ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_strlen.c ft_atoi.c ft_strlcpy.c ft_strnstr.c ft_printf.c ft_printf_utils2.c ft_printf_utils.c ft_printhexa.c ft_putptr.c ft_putunbr.c

OBJS = ${SRCS:.c=.o}

BONUS = ft_lstsize_bonus.c ft_lstclear_bonus.c ft_lstadd_back_bonus.c ft_lstlast_bonus.c  ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstdelone_bonus.c

BONUS_OBJS = $(BONUS:.c=.o)

HDRS = libft.h

all : $(NAME)

$(NAME) : $(OBJS)
				ar rc $(NAME) $(OBJS)

clean : 
				rm -f ${OBJS} ${BONUS_OBJS}

bonus :	${OBJS} ${BONUS_OBJS}
				ar rc ${NAME} ${OBJS} ${BONUS_OBJS}

fclean : clean
				rm -f ${NAME} 

re : fclean all

.PHONY : re fclean all bonus clean

NAME=libft.a
CC=cc
CFLAGS=-Wall -Werror -Wextra -ggdb
AR=ar rcs
STRING_SRC_PATH=./string/
STR_SRC_PATH=./str/
CTYPE_SRC_PATH=./ctype/
LLIST_SRC_PATH=./llist/
IO_SRC_PATH=./io/
STDLIB_SRC_PATH=./stdlib/
STRING_SRC_FILES=ft_strcat.c \
	ft_memcmp.c \
	ft_strndup.c \
	ft_memcpy.c \
	ft_strtok_r.c \
	ft_strrev.c \
	ft_strstr.c \
	ft_stpcpy.c \
	ft_strncpy.c \
	ft_memmove.c \
	ft_strcmp.c \
	ft_strncat.c \
	ft_strcpy.c \
	ft_strncmp.c \
	ft_strlen.c \
	ft_bzero.c \
	ft_strpbrk.c \
	ft_strnlen.c \
	ft_memset.c \
	ft_memccpy.c \
	ft_strcoll.c \
	ft_strchr.c \
	ft_stpncpy.c \
	ft_memchr.c \
	ft_strrchr.c \
	ft_strdup.c \
	ft_strspn.c \
	ft_strcspn.c \
	ft_strtok.c
STR_SRC_FILES=ft_strtrim.c \
	ft_substr.c \
	ft_strmapi.c \
	ft_strjoin.c \
	ft_split.c \
	ft_hashstr.c \
	ft_striteri.c \
	exp_string.c
CTYPE_SRC_FILES=ft_isblank.c \
	ft_isalpha.c \
	ft_isalnum.c \
	ft_isdigit.c \
	ft_isxdigit.c \
	ft_iscntrl.c \
	ft_isprint.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_ispunct.c \
	ft_isascii.c \
	ft_isspace.c \
	ft_islower.c \
	ft_isupper.c \
	ft_isgraph.c
LLIST_SRC_FILES=ft_lstdelone.c \
	ft_lstadd_front.c \
	ft_lstclear.c \
	ft_lstadd_back.c \
	ft_lstnew.c \
	ft_lstsize.c \
	ft_lstiter.c \
	ft_lstmap.c \
	ft_lstlast.c
IO_SRC_FILES=ft_count_flags.c \
	ft_putendl_fd.c \
	va_list_parser.c \
	ft_display_formatted.c \
	ft_printf.c \
	ft_putstr_fd.c \
	gnl.c \
	ft_itoa.c \
	ft_putchar_fd.c \
	ft_parse_flags.c \
	ft_ltoh.c \
	ft_putnbr_fd.c \
	join_formatted.c \
	parse_variadic.c \
	sprintf.c
STDLIB_SRC_FILES=ft_calloc.c \
	ft_div.c \
	ft_abs.c \
	ft_atoi.c \
	ft_itoa.c \
	free2d.c

STRING_FULL_PATH=$(addprefix $(STRING_SRC_PATH), $(STRING_SRC_FILES))
STR_FULL_PATH=$(addprefix $(STR_SRC_PATH), $(STR_SRC_FILES))
CTYPE_FULL_PATH=$(addprefix $(CTYPE_SRC_PATH), $(CTYPE_SRC_FILES))
LLIST_FULL_PATH=$(addprefix $(LLIST_SRC_PATH), $(LLIST_SRC_FILES))
IO_FULL_PATH=$(addprefix $(IO_SRC_PATH), $(IO_SRC_FILES))
STDLIB_FULL_PATH=$(addprefix $(STDLIB_SRC_PATH), $(STDLIB_SRC_FILES))
STRING_OBJ=$(STRING_FULL_PATH:.c=.o)
STR_OBJ=$(STR_FULL_PATH:.c=.o)
CTYPE_OBJ=$(CTYPE_FULL_PATH:.c=.o)
LLIST_OBJ=$(LLIST_FULL_PATH:.c=.o)
IO_OBJ=$(IO_FULL_PATH:.c=.o)
STDLIB_OBJ=$(STDLIB_FULL_PATH:.c=.o)

$(NAME): $(STRING_OBJ) $(STR_OBJ) $(CTYPE_OBJ) $(LLIST_OBJ) $(IO_OBJ) $(STDLIB_OBJ)
	$(AR) $@ $^

all: $(NAME)

clean:
	rm -f $(STRING_OBJ)
	rm -f $(STR_OBJ)
	rm -f $(CTYPE_OBJ)
	rm -f $(LLIST_OBJ)
	rm -f $(IO_OBJ)
	rm -f $(STDLIB_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

default: all

.PHONY: default all re fclean clean
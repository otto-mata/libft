#This makefile was auto generated, ain't no way I'm writing all that by hand
NAME=libft.a
CC=cc
CFLAGS=-Wall -Werror -Wextra -std=c89
AR=ar rcs
CTYPE_SRC_PATH=./ctype/
IO_SRC_PATH=./io/
LLIST_SRC_PATH=./llist/
STDLIB_SRC_PATH=./stdlib/
STR_SRC_PATH=./str/
STRING_SRC_PATH=./string/
BTREE_SRC_PATH=./btree/
GC_SRC_PATH=./gc/
ARGS_SRC_PATH=./args/
VEC3_SRC_PATH=./vec3/
OHT_SRC_PATH=./oht/
CSTM_SRC_PATH=./cstm/
LLIST_GC_SRC_PATH=./llist_gc/
CTYPE_SRC_FILES=ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isblank.c \
	ft_iscntrl.c \
	ft_isdigit.c \
	ft_isgraph.c \
	ft_islower.c \
	ft_isprint.c \
	ft_ispunct.c \
	ft_isspace.c \
	ft_isupper.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_isxdigit.c
IO_SRC_FILES=ft_count_flags.c \
	ft_display_formatted.c \
	ft_itoa.c \
	ft_ltoh.c \
	ft_parse_flags.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	gnl.c \
	join_formatted.c \
	parse_variadic.c \
	sprintf.c \
	va_list_parser.c \
	ft_dprintf.c
LLIST_SRC_FILES=ft_lstadd_back.c \
	ft_lstadd_front.c \
	ft_lstclear.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstlast.c \
	ft_lstmap.c \
	ft_lstnew.c \
	ft_lstsize.c
STDLIB_SRC_FILES=free2d.c \
	ft_abs.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_div.c \
	ft_itoa.c \
	ft_realloc.c
STR_SRC_FILES=exp_string.c \
	ft_hashstr.c \
	ft_split.c \
	ft_striteri.c \
	ft_strmapi.c \
	ft_strtrim.c \
	replace.c \
	ft_strjoin.c \
	ft_substr.c
STRING_SRC_FILES=ft_bzero.c \
	ft_memccpy.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_stpcpy.c \
	ft_stpncpy.c \
	ft_strchr.c \
	ft_strcmp.c \
	ft_strcoll.c \
	ft_strcpy.c \
	ft_strcspn.c \
	ft_strlen.c \
	ft_strncat.c \
	ft_strncmp.c \
	ft_strncpy.c \
	ft_strndup.c \
	ft_strnlen.c \
	ft_strpbrk.c \
	ft_strrchr.c \
	ft_strrev.c \
	ft_strspn.c \
	ft_strstr.c \
	ft_strtok.c \
	ft_strtok_r.c \
	ft_strdup.c \
	ft_strcat.c
BTREE_SRC_FILES=btree_apply_prefix.c \
	btree_insert_data.c \
	btree_apply_infix.c \
	btree_apply_suffix.c \
	btree_create_node.c \
	btree_search_node.c \
	btree_level_count.c \
	btree_apply_by_level.c
GC_SRC_FILES=otto_bzero.c \
	otto_memcpy.c \
	otto_min.c \
	gc_addback.c \
	gc_addfront.c \
	gc_nblocks.c \
	gc_calloc.c \
	gc_clear.c \
	gc_delblock.c \
	gc_addr_find.c \
	gc_addr_find_prev.c \
	gc_free.c \
	gc_instance.c \
	gc_last.c \
	gc_malloc.c \
	gc_newblock.c \
	gc_realloc.c
ARGS_SRC_FILES=args_use_argv.c \
	args_validate.c \
	args_destroy.c \
	args_instance.c \
	args_prepare.c \
	args_register_handler.c
VEC3_SRC_FILES=vec3_add.c \
	vec3_copy.c \
	vec3_cross.c \
	vec3_div_scalar.c \
	vec3_dot.c \
	vec3_ip_add.c \
	vec3_ip_div.c \
	vec3_ip_mult.c \
	vec3_ip_sub.c \
	vec3_len.c \
	vec3_mult.c \
	vec3_mult_scalar.c \
	vec3_new.c \
	vec3_sqrd_len.c \
	vec3_sub.c \
	vec3_unit.c
OHT_SRC_FILES=oht.c \
	oht_utils.c
CSTM_SRC_FILES=d2i.c
LLIST_GC_SRC_FILES=ftgc_lstadd_back.c \
	ftgc_lstadd_front.c \
	ftgc_lstclear.c \
	ftgc_lstdelone.c \
	ftgc_lstiter.c \
	ftgc_lstlast.c \
	ftgc_lstmap.c \
	ftgc_lstnew.c \
	ftgc_lstsize.c
CTYPE_FULL_PATH=$(addprefix $(CTYPE_SRC_PATH), $(CTYPE_SRC_FILES))
IO_FULL_PATH=$(addprefix $(IO_SRC_PATH), $(IO_SRC_FILES))
LLIST_FULL_PATH=$(addprefix $(LLIST_SRC_PATH), $(LLIST_SRC_FILES))
STDLIB_FULL_PATH=$(addprefix $(STDLIB_SRC_PATH), $(STDLIB_SRC_FILES))
STR_FULL_PATH=$(addprefix $(STR_SRC_PATH), $(STR_SRC_FILES))
STRING_FULL_PATH=$(addprefix $(STRING_SRC_PATH), $(STRING_SRC_FILES))
BTREE_FULL_PATH=$(addprefix $(BTREE_SRC_PATH), $(BTREE_SRC_FILES))
GC_FULL_PATH=$(addprefix $(GC_SRC_PATH), $(GC_SRC_FILES))
ARGS_FULL_PATH=$(addprefix $(ARGS_SRC_PATH), $(ARGS_SRC_FILES))
VEC3_FULL_PATH=$(addprefix $(VEC3_SRC_PATH), $(VEC3_SRC_FILES))
OHT_FULL_PATH=$(addprefix $(OHT_SRC_PATH), $(OHT_SRC_FILES))
CSTM_FULL_PATH=$(addprefix $(CSTM_SRC_PATH), $(CSTM_SRC_FILES))
LLIST_GC_FULL_PATH=$(addprefix $(LLIST_GC_SRC_PATH), $(LLIST_GC_SRC_FILES))
CTYPE_OBJ=$(CTYPE_FULL_PATH:.c=.o)
IO_OBJ=$(IO_FULL_PATH:.c=.o)
LLIST_OBJ=$(LLIST_FULL_PATH:.c=.o)
STDLIB_OBJ=$(STDLIB_FULL_PATH:.c=.o)
STR_OBJ=$(STR_FULL_PATH:.c=.o)
STRING_OBJ=$(STRING_FULL_PATH:.c=.o)
BTREE_OBJ=$(BTREE_FULL_PATH:.c=.o)
GC_OBJ=$(GC_FULL_PATH:.c=.o)
ARGS_OBJ=$(ARGS_FULL_PATH:.c=.o)
VEC3_OBJ=$(VEC3_FULL_PATH:.c=.o)
OHT_OBJ=$(OHT_FULL_PATH:.c=.o)
CSTM_OBJ=$(CSTM_FULL_PATH:.c=.o)
LLIST_GC_OBJ=$(LLIST_GC_FULL_PATH:.c=.o)

$(NAME): $(CTYPE_OBJ) $(IO_OBJ) $(LLIST_OBJ) $(STDLIB_OBJ) $(STR_OBJ) $(STRING_OBJ) $(BTREE_OBJ) $(GC_OBJ) $(ARGS_OBJ) $(VEC3_OBJ) $(OHT_OBJ) $(CSTM_OBJ) $(LLIST_GC_OBJ)
	$(AR) $@ $^

all: $(NAME)

clean:
	rm -f $(CTYPE_OBJ)
	rm -f $(IO_OBJ)
	rm -f $(LLIST_OBJ)
	rm -f $(STDLIB_OBJ)
	rm -f $(STR_OBJ)
	rm -f $(STRING_OBJ)
	rm -f $(BTREE_OBJ)
	rm -f $(GC_OBJ)
	rm -f $(ARGS_OBJ)
	rm -f $(VEC3_OBJ)
	rm -f $(OHT_OBJ)
	rm -f $(CSTM_OBJ)
	rm -f $(LLIST_GC_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

default: all

.PHONY: default all re fclean clean
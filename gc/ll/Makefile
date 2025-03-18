NAME=libosgc.a
SRC=osgc_clear.c \
	osgc_addblock_front.c \
	osgc_delblock.c \
	osgc_malloc.c \
	osgc_addblock_back.c \
	osgc_newblock.c \
	otto_bzero.c \
	osgc_blocksz.c \
	osgc_calloc.c \
	osgc_lastblock.c \
	osgc_instance.c \
	osgc_realloc.c \
	otto_memcpy.c \
	otto_min.c \
	osgc_find_by_address.c \
	osgc_find_prev_by_address.c \
	osgc_free.c

OBJS=$(SRC:.c=.o)
AR=ar rc
LIB=ranlib
CC=clang
CFLAGS=-Wall -Wextra -Werror -g3

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^
	$(LIB) $@

clean:		 
	rm -f $(OBJS) $(OBJS_BONUS) $(NAME_BONUS)

fclean: clean					
	rm -f $(NAME)

re: fclean  all

default: all
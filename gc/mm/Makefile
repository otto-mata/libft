NAME=libmm.a
SRC=allocations.c \
	block.c \
	destroy.c \
	free.c \
	init.c \
	page.c \
	utilities.c

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

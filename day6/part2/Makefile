NAME = d6p2

C_FILES =	main.c \

O_FILES = $(C_FILES:.c=.o)

DIR_OBJS = ./obj/
DIR_LIBFT = ../../lib/libft

vpath %.c $(DIR_SRCS) $(DIR_OBJS)

OBJS = $(O_FILES:%=$(DIR_OBJS)%)

CC = gcc
# CFLAGS = -Wall -Wextra -Werror
INC = -Iinc -I$(DIR_LIBFT)

LIBFT = $(DIR_LIBFT)/libft.a

all:
	@$(MAKE) $(NAME) -j4

$(NAME): $(DIR_OBJS) $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(INC) $(LIBFT)

$(DIR_OBJS)%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(DIR_OBJS):
	mkdir -p $@

$(LIBFT):
	make -C $(DIR_LIBFT)
	@echo "libft made!"

clean:
	make -C $(DIR_LIBFT) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(DIR_LIBFT) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
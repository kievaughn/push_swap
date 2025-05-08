CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I./includes -I./

TARGET = push_swap
OBJ_PATH = obj/

SRCS = src/main.c \
       src/operations.c \
       src/operations_2.c \
       src/sort.c \
       src/calculations.c \
       src/utils.c \
       src/push_swap.c \
       src/libft/ft_atoi.c \
       src/libft/ft_lstadd_back_bonus.c \
       src/libft/ft_lstclear_bonus.c \
       src/libft/ft_lstadd_front_bonus.c \
       src/libft/ft_lstnew_bonus.c \
       src/libft/ft_lstsize_bonus.c \
       src/printf/ft_printf.c \
       src/printf/ft_putchar.c \
       src/printf/ft_puthex.c \
       src/printf/ft_putnbr_u.c \
       src/printf/ft_putnbr.c \
       src/printf/ft_putstr.c

OBJS = $(SRCS:src/%.c=$(OBJ_PATH)%.o)
HEADERS = includes/push_swap.h

$(OBJ_PATH)%.o: src/%.c $(HEADERS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re

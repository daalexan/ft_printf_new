NAME = libftprintf.a

HEADER = ./include/libft/
PRINT_HEADER = ./include/

SRC = src

CFLAGS = -Wall -Werror -Wextra

CC = gcc

LIB_FILES = ./include/libft/
PRINTF_FILES =  src/ft_parse.c \
				src/ft_printf.c \
				src/edition/ft_init.c \
				src/edition/ft_space.c \
				src/edition/ft_nbrlen.c \
				src/edition/ft_convert.c \
				src/handlers/ft_str/ft_str_handle.c \
				src/handlers/ft_int/ft_int_handle.c \
				src/handlers/ft_int/ft_pref_handle.c \
				src/handlers/ft_int/ft_dint_handle.c \
				src/handlers/ft_int/ft_prntint.c \
				src/handlers/ft_hex/ft_hex_handle.c \
				src/handlers/ft_hex/ft_print_hex.c \
				src/handlers/ft_char/ft_char_handle.c \
				src/handlers/ft_long/ft_long_handle.c \
				src/handlers/ft_wchar/ft_wchar_handle.c \
				src/handlers/ft_wchar/ft_print_wchar.c \
				src/handlers/ft_unsig/ft_unsig_handle.c \
				src/handlers/ft_octal/ft_octal_handle.c \
				src/handlers/ft_octal/ft_octlen.c \
				src/handlers/ft_wstr/ft_wstr_handle.c \
				src/handlers/ft_nothing/ft_nth_handle.c \
				src/handlers/ft_binary/ft_binary_handle.c \
				src/handlers/ft_ptr/ft_ptr_handle.c \
				src/handlers/ft_float/ft_float_handle.c \
				src/handlers/ft_float/ft_scinot_handle.c \
				src/handlers/ft_float/ft_prnt.c
OBJ = $(PRINTF_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIB_FILES)libft.a
	ar rc $(NAME) $(OBJ) $(LIB_FILES)*.o
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER) -I $(PRINT_HEADER)

$(LIB_FILES)libft.a:
	make -C $(LIB_FILES)
clean:
	make clean -C $(LIB_FILES)
	rm -f $(OBJ)
fclean: clean
	make fclean -C $(LIB_FILES)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

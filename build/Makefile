NAME = ../push_swap
BNAME= ../checker

LIBFT_DIR   := ../submodules/42_libft
FTPRINTF_DIR:= ../submodules/42_ft_printf
FTGNL_DIR   := ../submodules/42_get_next_line

SRC = $(shell find ../src -name "*.c")
BSRC = $(shell find ../src_bonus -name "*.c")
OBJ = $(SRC:.c=.o)
BOBJ = $(BSRC:.c=.o) $(filter-out ../src/main.o, $(OBJ))

CFLAGS		:=	-Wall -Werror -Wextra \
				#-Wunreachable-code -Ofast -g # -fsanitize=address
HEADER		:=	-I../include/
LIBS		:=	-L$(LIBFT_DIR) -lft \
				-L$(FTPRINTF_DIR) -lftprintf \
				-L$(FTGNL_DIR) -lftgnl

$(NAME): $(LIBFT_DIR)/libft.a $(FTPRINTF_DIR)/ftprintf.a $(FTGNL_DIR)/ftgnl.a $(OBJ)
	@cc $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)
$(BNAME): $(LIBFT_DIR)/libft.a $(FTPRINTF_DIR)/ftprintf.a $(FTGNL_DIR)/ftgnl.a $(BOBJ)
	@cc $(CFLAGS) $(BOBJ) $(LIBS) -o $(BNAME)
%.o: %.c
	@cc -c $< $(CFLAGS) $(HEADER) -o $@

$(LIBFT_DIR)/libft.a:
	make -C $(LIBFT_DIR) comp

$(FTPRINTF_DIR)/ftprintf.a:
	make -C $(FTPRINTF_DIR)

$(FTGNL_DIR)/ftgnl.a:
	make -C $(FTGNL_DIR)

all: $(NAME)
bonus: $(BNAME)
clean:
	@rm -f $(OBJ) $(BOBJ)
	make -C $(LIBFT_DIR) clean
	make -C $(FTPRINTF_DIR) clean
	make -C $(FTGNL_DIR) clean
fclean: clean
	make -C $(LIBFT_DIR) fclean
	make -C $(FTPRINTF_DIR) fclean
	make -C $(FTGNL_DIR) fclean
	@rm -f $(NAME) $(BNAME)
re: fclean all

comp:
	@make all
	@make bonus
	@make clean
	@clear
fcomp:
	@cd ../ && git submodule update --init --remote
	@cd ../include && norminette
	@cd ../src && norminette
	@make re
	@make clean
	@clear

.PHONY: all clean fclean re comp fcomp bonus

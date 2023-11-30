NAME = ../push_swap
BNAME= ../checker

LIBFT_DIR   := ../submodules/42_libft
FTPRINTF_DIR:= ../submodules/42_ft_printf
FTGNL_DIR   := ../submodules/42_get_next_line

SRC = $(shell find ../src -name "*.c")
BSRC = $(shell find ../src_bonus -name "*.c")
OBJ = $(SRC:.c=.o)
BOBJ = $(BSRC:.c=.o)

CFLAGS		:=	-Wall -Werror -Wextra \
				-Wunreachable-code -Ofast -g # -fsanitize=address
HEADER		:=	-I../include/
LIBS		:=	-L$(LIBFT_DIR) -lft \
				-L$(FTPRINTF_DIR) -lftprintf \
				-L$(FTGNL_DIR) -lftgnl

$(NAME): $(OBJ)
	@cc $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)
$(BNAME): $(BOBJ)
	@cc $(CFLAGS) $(filter-out ../src/main.o, $(SRC:.c=.o)) $(BOBJ) $(LIBS) -o $(BNAME)
%.o: %.c
	@cc -c $< $(CFLAGS) $(HEADER) -o $@

libft:
	make comp -C $(LIBFT_DIR)
ftprintf:
	make -C $(FTPRINTF_DIR)
ftgnl:
	make -C $(FTGNL_DIR)

all: libft ftprintf ftgnl $(NAME)
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
	@cd ../ && git submodule update --init --recursive
	@cd ../submodules && norminette
	@cd ../include && norminette
	@cd ../src && norminette
	@make re
	@make clean
	@clear

.PHONY: all clean fclean re comp fcomp bonus libft ftprintf ftgnl

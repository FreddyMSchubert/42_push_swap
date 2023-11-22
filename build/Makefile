NAME = ../push_swap
BNAME= ../checker

SRC = $(shell find ../src -name "*.c")
BSRC = $(shell find ../src_bonus -name "*.c")
OBJ = $(SRC:.c=.o)
BOBJ = $(BSRC:.c=.o)

CHSRC = $(shell find ../submodules/42_get_next_line -name "*.c")

CFLAGS		:= -Wall -Werror -Wextra \
				-Wunreachable-code -Ofast #-g -fsanitize=address
HEADER		:= -I../include/
LIBS		:=	-L../submodules/42_ft_printf/ -lftprintf \
				-L../submodules/42_libft/ -lft

$(NAME): $(OBJ)
	@cc $(CFLAGS) $(LIBS) $(OBJ) -o $(NAME)
$(BNAME): $(BOBJ)
	@cc $(CFLAGS) $(LIBS) $(filter-out ../src/main.o, $(SRC:.c=.o)) $(BOBJ) $(CHSRC) -o $(BNAME)
%.o: %.c
	@cc -c $< $(CFLAGS) $(HEADER) -o $@

all: $(NAME) $(BNAME)
push_swap: $(NAME)
bonus: $(BNAME)
clean:
	@rm -f $(OBJ) $(BOBJ)
fclean: clean
	@rm -f $(NAME) $(BNAME)
re: fclean all
fcomp:
	@cd ../include && norminette
	@cd ../src && norminette
	@make re
	@make clean
	@clear
comp:
	@make all
	@make clean
	@clear

.PHONY: all clean fclean re comp

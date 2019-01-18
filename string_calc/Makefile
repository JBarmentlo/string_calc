NAME=string_calc
SOURCES= string_calc.c littlelib.c ft_strlen.c ft_strdup.c
OBJ_FOLDER=out
OUT=$(addprefix $(OBJ_FOLDER)/,$(SOURCES:.c=.o))
CFLAGS=-Wall -Werror -Wextra

all: $(NAME)

$(NAME) : $(OUT)
	gcc $(CFLAGS) -o $(NAME) $(OUT)

$(OBJ_FOLDER)/%.o: Sources/%.c
	@mkdir -p $(OBJ_FOLDER)
	gcc $(CFLAGS) -I Includes -o $@ -c $<

clean:
	rm -rf $(OBJ_FOLDER)

fclean: clean
		rm -rf $(NAME)

re: fclean all

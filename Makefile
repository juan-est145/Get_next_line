NAME = get_next_line.a

SCRS = get_next_line.c\
get_next_line_utils.c

OBJS = $(SCRS:.c=.o)

SCRS_BONUS = get_next_line_bonus.c\
get_next_line_utils_bonus.c

OBJS_BONUS = $(SCRS_BONUS:.c=.o)

HEADER = get_next_line.h

BONUS_HEADER = get_next_line_bonus.h

STATIC_LIB = ar rcs

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(STATIC_LIB) $(NAME) $(OBJS)

bonus: $(OBJS_BONUS) $(BONUS_HEADER)
	$(STATIC_LIB) $(NAME) $(OBJS_BONUS)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

debug:
	clang -Wall -Wextra -Werror -g *.c

valgrind:
	valgrind --leak-check=full -s --track-origins=yes ./a.out

.Phony: all clean fclean re bonus
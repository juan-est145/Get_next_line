NAME = get_next_line.a

SCRS = get_next_line.c\
get_next_line_utils.c

OBJS = $(SCRS:.c=.o)

HEADER = get_next_line.h

STATIC_LIB = ar rcs

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(STATIC_LIB) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

.Phony: all clean fclean re bonus
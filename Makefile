NAME			=	push_swap

BONUS_NAME		=	checker

SRCS			=	push_swap.c push_swap_ps.c\
					push_swap_r.c push_swap_rr.c\
					push_swap_utils.c\
					sort.c sort1.c sort2.c\
					sort3.c

BONUS_SRCS		=	push_swap_bonus.c get_next_line.c\
					get_next_line_utils.c push_swap_ps.c\
					push_swap_r.c push_swap_rr.c\
					sort.c sort1.c sort2.c\
					sort3.c push_swap_utils.c\

HEADER			=	push_swap.h

BONUS_HEADER	=	push_swap_bonus.h

OBJS			=	$(SRCS:%.c=%.o)

BONUS_OBJS		=	$(BONUS_SRCS:%.c=%.o)

CC				=	gcc

FLAGS			=	-Wall -Werror -Wextra

RM				=	rm -f

all:			$(NAME)

%.o:			%.c $(HEADER)
				$(CC) $(FLAGS) -c $< -o $@

$(NAME):		$(OBJS) $(HEADER)
				$(CC) $(OBJS) -o $(NAME)

clean:
				@$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				@$(RM) $(NAME) $(BONUS_NAME)

re:				fclean all

bonus:			$(BONUS_NAME)

$(BONUS_NAME):	$(BONUS_OBJS) $(BONUS_HEADER)
				$(CC) $(BONUS_OBJS) -o $(BONUS_NAME)

.PHONY: all clean fclean re bonus
NAME = push_swap

CC = cc

MY_SOURCES = push_swap.c \
			 actions/pa.c \
			 actions/pb.c \
			 actions/ra.c \
			 actions/rb.c \
			 actions/rr.c \
			 actions/rra.c \
			 actions/rrb.c \
			 actions/rrr.c \
			 actions/sa.c \
			 actions/sb.c \
			 actions/ss.c \
			 parsing/assembleur.c \
			 parsing/verif.c \
			 parsing/ft_atoi.c \
			 parsing/ft_lstadd_back.c \
			 parsing/ft_lstclear.c \
			 parsing/ft_lstnew.c \
			 parsing/ft_split.c \
			 parsing/ft_strjoin.c \
			 parsing/ft_strdup.c \
			 parsing/ft_strlen.c \
			 parsing/second_errorcase.c \
			 presort/ranking.c \
			 presort/buckets.c \
			 presort/sort.c \
			 apply_scenario/calculs.c \
			 apply_scenario/apply_scenario.c \
			 apply_scenario/scenario_suite.c \
			 find_position/find_position.c \
			 find_position/utils.c \
			 
			 
 



MY_OBJECTS = $(MY_SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g3

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(MY_OBJECTS)
	$(CC) $(CFLAGS) $(MY_OBJECTS) $(LIBFT) -o $(NAME)

all: $(NAME)

clean: 
		rm -f $(MY_OBJECTS)

fclean: clean
		rm -f $(NAME)

re: fclean all
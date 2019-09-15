NAME = push_swap
NAME_CH = checker
PSSRC = push_swap.c ft_qsort.c atoi_push_swap.c p.c r.c rr.c s.c stack.c
PSOBJ = $(PSSRC:.c=.o)

all: $(NAME) $(NAME_CH)

libftprintf:
	make -C printf re

$(NAME): libftprintf
	gcc -Wall -Wextra -Werror -I . -c $(PSSRC)
	gcc -o $(NAME) $(PSOBJ) -I . -L printf/ -lftprintf

$(NAME_CH): libftprintf

clean:

fclean: clean

re: fclean all

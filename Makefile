NAME = push_swap
NAME_CH = checker
PSSRC = push_swap.c ft_qsort.c atoi_push_swap.c p.c r.c rr.c s.c stack.c main_ps.c find.c set.c presort.c services.c five.c free_and_allocs.c
PSOBJ = $(PSSRC:.c=.o)
CHSRC = ft_qsort.c main_ch.c checker.c s.c p.c r.c rr.c atoi_push_swap.c stack.c services.c get_next_line.c visual.c checker_main_help.c free_and_allocs.c
CHOBJ = $(CHSRC:.c=.o)

all: $(NAME) $(NAME_CH)

$(NAME): $(PSOBJ)
	make -C printf re
	gcc -Wall -Wextra -Werror -o $(NAME) $(PSOBJ) -Iprintf -I. -Ilibft -L printf/ -lftprintf

$(NAME_CH): $(CHOBJ)
	make -C printf re
	gcc -Wall -Wextra -Werror -o $(NAME_CH) $(CHOBJ) -Iprintf -I. -Ilibft -L printf/ -lftprintf

%.o: %.c push_swap.h checker.h
	gcc -Wall -Wextra -Werror -o $@ -c $< -Iprintf -I. -Ilibft

clean:
	make -C printf clean
	rm -rf *.o

fclean: clean
	make -C printf fclean
	rm -rf $(NAME)
	rm -rf $(NAME_CH)

re: fclean all

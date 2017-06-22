
OBJS = checker.o do.o dummies.o in8.o list_basics.o list_helpers.o list_manip.o \
		load.o map.o misc.o pats.o post.o solver.o paint.o error.o do_4.o instr.o small.o debug.o
DEMO_OBJS = demo_srcs/demo.o demo_srcs/prints.o

PS_OBJS = solvemain.o

CHECK_OBJS = checkmain.o

LIB = libft/libft.a

FLAGS = -Wall -Wextra -Werror -O2

all: push_swap checker

push_swap: $(LIB) $(OBJS) $(PS_OBJS)
	gcc -o push_swap $(FLAGS) $(LIB) $(OBJS) $(PS_OBJS)
checker: $(LIB) $(OBJS) $(CHECK_OBJS)
	gcc -o checker $(FLAGS) $(LIB) $(OBJS) $(CHECK_OBJS)
demo: $(LIB) $(OBJS) $(DEMO_OBJS)
	gcc -o demo $(FLAGS) $(LIB) $(OBJS) $(DEMO_OBJS)
%.o: %.c
	gcc $(FLAGS) -c -o $@ $<
libft/libft.a: 
	make -C libft
clean:
	rm -f $(OBJS) $(DEMO_OBJS) $(PS_OBJS) $(CHECK_OBJS)
	make -C libft clean
fclean: clean
	rm -f push_swap checker demo
	make -C libft fclean
re:	fclean all

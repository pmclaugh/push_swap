/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmclaugh <pmclaugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 19:37:32 by pmclaugh          #+#    #+#             */
/*   Updated: 2017/04/24 20:09:28 by pmclaugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H
# include "libft/includes/libft.h"
# include "libft/includes/ft_printf.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

enum			e_instr
{
	SA,
	SB,
	PA,
	PB,
	RA,
	RB,
	RRA,
	RRB,
	RR,
	RRR,
	SS
};

enum			e_fintype
{
	IN4,
	TR4,
	IN8,
	TR8
};

typedef struct	s_list
{
	int				val;
	struct s_list	*next;
}				t_list;

typedef struct	s_kit
{
	t_list			**a;
	t_list			**b;
	t_list			**in;
	int				*abcd;
	int				*ops;
	enum e_fintype	fin;
}				t_kit;

void			print_instr_stderr(t_list *list);
void			print_list_stderr(t_list *list);
char			*instr_to_str_nonl(enum e_instr in);

void			follow_instructions_list(t_list *in, t_list **a, t_list **b);
enum e_instr	str_to_instr(char *str);
void			check_stdin(int ac, char **av);
void			check_file(t_list *in, char *nums_file);

void			tuck(t_list **a, t_list **b, t_list **in, int rev);
void			do_map(t_list **a, t_list **b, t_list **in, int *map);
t_kit			*new_kit(t_list **a, t_list **b, t_list **in, int *abcd);
void			do_ops_kit(int *ops, t_kit *kit, int count, int rev);
void			do_tr8(t_list **a, t_list **b, t_list **in);

void			add_vec(int *a, int *b, int count);
void			do_tr4(t_list **a, t_list **b, t_list **in);
void			do_in4(t_list **a, t_list **b, t_list **in);

void			make_dummies(t_list *stack);
int				affects_dum(t_list **a, t_list **b, enum e_instr in, int max);
void			make_move_dum(t_list **a, t_list **b, t_list *in, int max);
t_list			*remove_dummies(t_list *a, t_list *in);

int				is_numbers(char *str);
int				check_errors(char **split);
int				check_dupes(int *arr, int count);

int				*make_sequence(int start, int diff, int width, int count);
int				*in8map(int elemcount);
void			do_tr4_in8(t_list **a, t_list **b, t_list **in);
void			do_in4_in8(t_list **a, t_list **b, t_list **in);
void			do_in8(t_list **a, t_list **b, t_list **in);

int				*list_to_arr(t_list *list, int *count);
t_list			*arr_to_list(int *arr, int count);
t_list			*new_node(int val);
t_list			*lstat(t_list *begin_list, unsigned int i);
void			ft_listplug(t_ftlist **queue, t_ftlist *new);

int				is_sorted(t_list *list);
void			free_list(t_list *list);
t_list			*dupe_list(t_list *list);
void			print_list(t_list *list);
int				lstlen(t_list *begin_list);

void			push(t_list **stack, t_list *node);
t_list			*pop(t_list **stack);
void			plug(t_list **stack, t_list *node);
t_list			*pluck(t_list **stack);
t_list			*tail(t_list *head);

t_list			*load(int ac, char **av);
char			**load_file(char *file);
t_list			*stack_from_args(int ac, char **av);
t_list			*stack_from_string(char *str);
t_list			*stack_from_file(char *file);

int				map_val(int n, int count);
int				*in4map(int count);
int				*tr4map(int count);
int				*tr8map(int count);

enum e_fintype	plan(int n);
int				count_maps(int **maps);
int				splitlen(char **split);
int				*base_map(int elemcount, enum e_fintype fin);
int				count_lines(char *file);

int				**paint(int count, int end_section_size);
void			paint_flat(int **maps, int divcount, int count);
void			paint_ordinals(int *arr, int len);

int				*grab_next_n(t_list *a, int n);
char			*recognize_8pat(char **patterns, int *eight, int abcd[4]);
char			*recognize_4pat(char **patterns, int *four, int abcd[4]);
char			*match(char *str, char **split);
int				*make_instr_arr(char *str);

void			condense(t_list *in);
int				is_rotationally_sorted(t_list *list);
void			free_split(char **split);

void			make_move(t_list **a, t_list **b, t_list **in, enum e_instr i);
void			swap(t_list **stack);
void			rot_up(t_list **stack);
void			rot_down(t_list **stack);

char			*instr_to_str(enum e_instr in);
enum e_instr	opposite_instr(enum e_instr in);
enum e_instr	mirr_instr(enum e_instr in, int flag);
void			instructions_to_stdout(t_list *in);

int				good_move(t_list *in, enum e_instr i);
void			free_and_advance(t_ftlist **queue, t_list *b);
int				good_solution(t_list *a, t_list *in);
void			populate_queue(t_ftlist **queue);
t_list			*bfs_brute(t_list *a);

void			print_label(int n);
void			print_trimap(int *map, int *map2, int *map3, int count);
void			status_print(t_list *a, t_list *b, int *map, int *map2);
int				status_display(t_kit *k, int *map, int *map2);
void			print_list_trimap(int *map, int *map2, int *map3, t_list *l);

#endif

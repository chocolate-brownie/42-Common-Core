/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:28:08 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/02 13:53:22 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* ------------------------------ */
/*         STRUCTURES             */
/* ------------------------------ */
/* Node structure for the doubly linked list */
typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	int					above_median;
	int					cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

/* Stack structure containing the head, tail, and size */
typedef struct s_stack
{
	t_stack_node		*head;
	t_stack_node		*tail;
	int					size;
}						t_stack;

/* ------------------------------ */
/*        FUNCTION PROTOTYPES     */
/* ------------------------------ */

/* Debugging functions */
void					print_stack(t_stack *stack, char *name);

/* Push_swap commands */
void					sa(t_stack *stack_a, bool print);
void					sb(t_stack *stack_b, bool print);
void					ss(t_stack *a, t_stack *b, bool print);
void					pa(t_stack *a, t_stack *b, bool print);
void					pb(t_stack *a, t_stack *b, bool print);
void					ra(t_stack *a, bool print);
void					rb(t_stack *b, bool print);
void					rr(t_stack *a, t_stack *b, bool print);
void					rra(t_stack *a, bool print);
void					rrb(t_stack *b, bool print);
void					rrr(t_stack *a, t_stack *b, bool print);

/* Sorting algorithms and tools */
void					sort_three(t_stack *stack_a);
void					sort_four_five(t_stack *stack_a, t_stack *stack_b,
							int size);
int						find_smallest_index(t_stack *stack);
void					move_to_top(t_stack *stack, int index);
void					turk_algorithm(t_stack *stack_a, t_stack *stack_b);
void					assign_indices(t_stack *stack);
void					divide_into_chunks(t_stack *stack_a, t_stack *stack_b,
							int chunk_size);
void					calculate_push_cost(t_stack *stack);
t_stack_node			*find_cheapest_node(t_stack *stack);

/* Error, clean up and other utils */
void					error_exit(void);
void					cleanup(t_stack *stack_a, t_stack *stack_b);
void					free_stack(t_stack *stack);
void					free_split(char **split);
long					ft_atol(char *str);

/* Argument handling and stack manipulation */
void					init_stack_null(t_stack **stack_a, t_stack **stack_b);
void					control_arguments(int argc, char **argv,
							t_stack *stack_a);
void					validate_argument(char **split_args, int argc, long nbr,
							t_stack *stack_a);
int						is_valid_integer(long nbr);
int						is_duplicate(t_stack *stack, int nbr);
void					push_to_stack(t_stack *stack, int nbr);
int						is_sorted(t_stack *stack);
void					swap_nodes(t_stack_node *node1, t_stack_node *node2);
void					swap_adjacent_nodes(t_stack_node *node1,
							t_stack_node *node2);
void					swap_non_adjacent_nodes(t_stack_node *node1,
							t_stack_node *node2);

#endif

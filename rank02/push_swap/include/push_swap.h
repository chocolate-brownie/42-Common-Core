/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:15:35 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/17 00:18:46 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

// ***** Linked List Structure *****
typedef struct s_stack_node
{
	int					value;
	int					current_position;
	int					push_price;
	int					above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

// ***** Utils *****
void					error_exit(void);
void					free_stack(t_stack_node **stack);
void					free_split(char **split_args);
void					free_resources(t_stack_node **stack, char **split_args);
char					**split(char *str, char delimiter);
long					ft_atol(const char *str);

// ***** Debugging *****
void					print_stack_details(t_stack_node *stack,
							char stack_name);
void					print_stack_normal(t_stack_node *stack);

// ***** Main Process *****
void					init_stack(t_stack_node **a, t_stack_node **b);
int						control_arguments(const int argc, char **argv,
							t_stack_node **a);

// ***** Stack Utils *****
void					create_stack(t_stack_node **a, char **argv);
int						stack_len(t_stack_node *stack);
static t_stack_node		*find_last_node(t_stack_node *stack);
static t_stack_node		*find_highest(t_stack_node *stack);

// ***** Sorting Algorithms *****
static void				swap(t_stack_node **head);
void					sa(t_stack_node **a, bool print);
void					sb(t_stack_node **b, bool print);
void					ss(t_stack_node **a, t_stack_node **b, bool print);
static void				push(t_stack_node **dest, t_stack_node **src);
void					pa(t_stack_node **a, t_stack_node **b, bool print);
void					pb(t_stack_node **b, t_stack_node **a, bool print);
static void				rotate(t_stack_node **stack);
void					ra(t_stack_node **a, bool print);
void					rb(t_stack_node **b, bool print);
void					rr(t_stack_node **a, t_stack_node **b, bool print);
static void				reverse_rotate(t_stack_node **stack);
void					rra(t_stack_node **a, bool print);
void					rrb(t_stack_node **b, bool print);
void					rrs(t_stack_node **a, t_stack_node **b, bool print);
void					tiny_sort(t_stack_node **a);

// ***** Turk Algorithms *****
void					push_swap(t_stack_node **a, t_stack_node **b);
void					init_nodes(t_stack_node *a, t_stack_node *b);
void					set_current_position(t_stack_node *stack);
static void				set_target_node(t_stack_node *a, t_stack_node *b);
void					set_price(t_stack_node *a, t_stack_node *b);
static void				move_nodes(t_stack_node **a, t_stack_node **b);
static void				rotate_both(t_stack_node **a, t_stack_node **b,
							t_stack_node *cheapest);
static void				reverse_rotate_both(t_stack_node **a, t_stack_node **b,
							t_stack_node *cheapest);
void					finish_rotation(t_stack_node **stack,
							t_stack_node *top_node, char stack_name);
static t_stack_node		*return_cheapest(t_stack_node *stack);

// ***** Input Validation  *****
int						is_valid_input(char **args);
int						duplicates(char **split_args);
int						is_consistent(int argc, char **argv);

#endif

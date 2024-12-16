/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:15:35 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/17 00:52:02 by mgodawat         ###   ########.fr       */
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
t_stack_node			*find_last_node(t_stack_node *stack);
t_stack_node			*find_smallest(t_stack_node *stack);

// ***** Sorting Algorithms *****
void					sa(t_stack_node **a, bool print);
void					sb(t_stack_node **b, bool print);
void					ss(t_stack_node **a, t_stack_node **b, bool print);
void					pa(t_stack_node **a, t_stack_node **b, bool print);
void					pb(t_stack_node **b, t_stack_node **a, bool print);
void					ra(t_stack_node **a, bool print);
void					rb(t_stack_node **b, bool print);
void					rr(t_stack_node **a, t_stack_node **b, bool print);
void					rra(t_stack_node **a, bool print);
void					rrb(t_stack_node **b, bool print);
void					rrr(t_stack_node **a, t_stack_node **b, bool print);
void					tiny_sort(t_stack_node **a);

// ***** Input Validation  *****
int						is_valid_input(char **args);
int						duplicates(char **split_args);
int						is_consistent(int argc, char **argv);

#endif

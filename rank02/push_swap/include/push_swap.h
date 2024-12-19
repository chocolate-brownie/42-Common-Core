/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:15:01 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/19 19:21:48 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

/**
 * Stack Node Structure
 * Represents a node in the stack containing value and metadata for sorting
 * Used to track position, costs, and relationships between nodes
 */
typedef struct s_stack_node
{
	int					value;
	int					position;
	int					target_index;
	int					move_cost;
	bool				is_above_median;
	bool				is_cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

/**
 * Input Processing Functions
 * Handle command line arguments and string parsing
 */
char					**split_input(char *str, char separator);
int						validate_syntax(char *number_str);
int						check_duplicates(t_stack_node *stack, int number);

/**
 * Memory Management Functions
 * Handle memory allocation and cleanup operations
 */
void					free_string_array(char **array);
void					cleanup_and_exit(t_stack_node **stack_a, char **array,
							bool is_split_input);
void					destroy_stack(t_stack_node **stack);

/**
 * Stack Initialization and Setup Functions
 * Create and initialize stack structures with required metadata
 */
void					initialize_stack(t_stack_node **stack_a, char **input,
							bool is_split_input);
void					initialize_node_metadata(t_stack_node *stack_a,
							t_stack_node *stack_b);
void					update_positions(t_stack_node *stack);
void					calculate_move_costs(t_stack_node *stack_a,
							t_stack_node *stack_b);
void					mark_cheapest_moves(t_stack_node *stack_b);

/**
 * Stack Utility Functions
 * Helper functions for stack operations and node management
 */
void					add_node(t_stack_node **stack, int value);
t_stack_node			*get_last_node(t_stack_node *stack);
t_stack_node			*find_min_node(t_stack_node *stack);
t_stack_node			*get_cheapest_node(t_stack_node *stack);
bool					is_stack_sorted(t_stack_node *stack);
int						get_stack_size(t_stack_node *stack);
void					complete_rotation(t_stack_node **stack,
							t_stack_node *node, char stack_id);

/**
 * Sorting Algorithm Functions
 * Implementation of different sorting strategies
 */
void					sort_three_elements(t_stack_node **stack_a);
void					sort_five_elements(t_stack_node **stack_a,
							t_stack_node **stack_b);
void					sort_stack(t_stack_node **stack_a,
							t_stack_node **stack_b);

/**
 * Stack Operations
 * Basic stack manipulation operations
 * Each function has a checker parameter to control output
 */
// Swap Operations
void					swap_a(t_stack_node **stack_a, bool checker);
void					swap_b(t_stack_node **stack_b, bool checker);
void					swap_both(t_stack_node **stack_a,
							t_stack_node **stack_b, bool checker);

// Push Operations
void					push_to_a(t_stack_node **stack_a,
							t_stack_node **stack_b, bool checker);
void					push_to_b(t_stack_node **stack_b,
							t_stack_node **stack_a, bool checker);

// Rotate Operations
void					rotate_a(t_stack_node **stack_a, bool checker);
void					rotate_b(t_stack_node **stack_b, bool checker);
void					rotate_both(t_stack_node **stack_a,
							t_stack_node **stack_b, bool checker);

// Reverse Rotate Operations
void					reverse_rotate_a(t_stack_node **stack_a, bool checker);
void					reverse_rotate_b(t_stack_node **stack_b, bool checker);
void					reverse_rotate_both(t_stack_node **stack_a,
							t_stack_node **stack_b, bool checker);

#endif
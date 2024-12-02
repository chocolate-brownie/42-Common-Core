/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:12:47 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/02 16:58:39 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

// ***** Linked List Structure *****
typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*head;
	t_node			*tail;
	int				size;
}					t_stack;

// ***** Initialization and Cleanup *****
void				initialize_stack(t_stack *stack);
void				free_stack(t_stack *stack);
void				clear_list(t_stack *stack, void (*del)(void *));
void				delete_content(void *content);
void				initialize_stack_with_args(t_stack *stack, int argc,
						char **argv);
void				free_arguments(char **argv);

// ***** Main Input Validation *****
void				check_arguments(int argc, char **argv);
char				**parse_arguments(int argc, char **argv);
void				validate_arguments(char **args, char **split_args);
// ***** Input Validation Tools *****
int					is_valid_integer(char *str);
int					has_duplicates(char **argv);

// ***** Other Utils *****
long				ft_atol(const char *str);
void				free_arguments(char **argv);
void				handle_error_exit(char **argv);

// ***** Debugging Utilities *****
void				print_stack(const t_stack *stack);

// ***** List Utilities *****
t_node				*create_node(int value);
void				add_node_to_back(t_stack *stack, t_node *new_node);
void				add_node_to_front(t_stack *stack, t_node *new_node);
t_node				*get_last_node(const t_stack *stack);
int					get_stack_size(const t_stack *stack);

// ***** Sorting Utilities *****
int					find_min_value(const t_stack *stack);
int					find_max_value(const t_stack *stack);
int					calculate_steps_to_target(const t_stack *stack, int target);
int					find_cheapest_push_to_b(t_stack *stack_a, t_stack *stack_b);
int					find_cheapest_push_to_a(t_stack *stack_b, t_stack *stack_a);

// ***** Commands *****
void				push_a(t_stack *stack_b, t_stack *stack_a);
void				push_b(t_stack *stack_a, t_stack *stack_b);
void				swap_a(t_stack *stack_a);
void				swap_b(t_stack *stack_b);
void				swap_both(t_stack *stack_a, t_stack *stack_b);
void				rotate_a(t_stack *stack_a);
void				rotate_b(t_stack *stack_b);
void				rotate_both(t_stack *stack_a, t_stack *stack_b);
void				reverse_rotate_a(t_stack *stack_a);
void				reverse_rotate_b(t_stack *stack_b);
void				reverse_rotate_both(t_stack *stack_a, t_stack *stack_b);

// ***** Sorting Logic *****
void				sort_small_stack(t_stack *stack_a, t_stack *stack_b,
						int size);
void				sort_large_stack(t_stack *stack_a, t_stack *stack_b,
						int size);
void				sort_three_nodes(t_stack *stack_a);
void				finalize_stack_sort(t_stack *stack_a);

// ***** Error Handling *****
void				handle_error(void);

#endif
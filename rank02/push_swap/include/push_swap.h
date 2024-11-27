/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:28:08 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/27 17:23:40 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				data;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_list	*target_node;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

/* utility functions & some libft extra functions */
void				error_exit(char *error_msg);
void				free_resources(t_list **stack, char **split);
int					ft_isspace(char c);
long				ft_atol(char *str);

/* stack manipulation */
void				init_stack_null(t_list **stack_a, t_list **stack_b);
t_list				*create_node(int data);
/* @note delete this functions afterwards its just for debugging purposes */
void				print_stack_data(t_list *stack);
void				print_stack(t_list *stack);

/* main argument handling functions */
t_list				*handle_arguments(int argc, char **argv);
t_list				*handle_single_string(char *arg);
t_list				*handle_multiple_arguments(int argc, char **argv);
bool				has_duplicates(t_list *stack);
bool				is_numeric(char *str);
void				add_to_stack(t_list **stack, int data);
bool				is_space_separated_string(const char *arg);
void				validate_mixed_input(int argc, char **argv);

/* sorting operatings */
void				sa(t_list **stack, bool print);
void				sb(t_list **stack, bool print);
void				ss(t_list **stack_a, t_list **stack_b, bool print);
void				pa(t_list **stack_a, t_list **stack_b, bool print);
void				pb(t_list **stack_a, t_list **stack_b, bool print);
void				ra(t_list **stack, bool print);
void				rb(t_list **stack, bool print);
void				rr(t_list **stack_a, t_list **stack_b, bool print);
void				rra(t_list **stack, bool print);
void				rrb(t_list **stack, bool print);
void				rrr(t_list **stack_a, t_list **stack_b, bool print);

#endif

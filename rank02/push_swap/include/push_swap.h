/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:28:08 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/28 15:00:53 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

/* ------------------------------ */
/*         STRUCTURES             */
/* ------------------------------ */

/* Structure representing the entire stack */
typedef struct s_stack
{
	t_list			**bgn_list;
	t_list			*last;
	int				list_size;
}					t_stack;
/* Structure representing a single node in the stack */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

/* ------------------------------ */
/*        FUNCTION PROTOTYPES     */
/* ------------------------------ */

/* Stack Manipulation */
void				initialize_stacks(t_stack *stack_a, t_stack *stack_b);
t_list				*create_node(void *content);

/* Utils */
void				error_exit(char *error_msg);
void				free_stack(char **split);
void				free_resources(t_stack *stack, char **split);
long				ft_atol(const char *str);

/* Handle Arguments */
void				handle_arguments(int argc, char **argv, t_stack *stack_a);
void				validate_and_push(char **numbers, t_stack **stack_a);
int					is_valid_number(const char *str);
int					add_to_stack(t_stack *stack, int num);
int					is_duplicate_in_stack(t_stack *stack, int num);
void				insert_node_to_stack(t_stack *stack, t_list *new_node);
t_list				*create_stack_node(int num);

#endif

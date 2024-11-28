/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:28:08 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/28 12:06:18 by mgodawat         ###   ########.fr       */
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

/* Handle Arguments */
void				handle_arguments(int argc, char **argv, t_stack *stack_a);
void				validate_and_push(char **numbers, t_stack **stack_a);

#endif

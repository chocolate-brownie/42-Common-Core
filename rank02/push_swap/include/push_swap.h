/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:28:08 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/27 15:19:24 by mgodawat         ###   ########.fr       */
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

void				error_exit(const char *error_msg);
void				free_resources(t_list **stack, char **split);
int					ft_isspace(char c);
long				ft_atol(char *str);

void				init_stack_null(t_list **stack_a, t_list **stack_b);
void				print_stack(t_list *stack);

t_list				*handle_arguments(int argc, char **argv);



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

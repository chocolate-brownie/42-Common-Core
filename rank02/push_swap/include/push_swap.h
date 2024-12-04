/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milan-godawatta <milan-godawatta@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:12:47 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/04 17:31:23 by milan-godaw      ###   ########.fr       */
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

// ***** Linked List Structure *****
typedef struct s_stack_node
{
	int					value;
	int					current_position;
	int					final_index;
	int					push_price;
	int					above_median;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

// ***** Utils *****
void					error_exit(void);
// ***** Custom Split Function *****
char					**custom_split(char *str, char seperator);
static int				count_words(char *str, char seperator);

// ***** Main Process *****
void					init_stack(t_stack_node **a, t_stack_node **b);
int						control_arguments(int argc, char **argv,
							t_stack_node **a);

#endif
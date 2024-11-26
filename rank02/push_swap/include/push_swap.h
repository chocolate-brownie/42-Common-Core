/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:28:08 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/26 18:02:34 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "../libft/libft.h"
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_list
{
    int data;
    int index;
    int push_cost;
    bool above_median;
    bool cheapest;
    struct s_list *target_node;
    struct s_list *next;
    struct s_list *prev;
} t_list;

/* utility functions */
void error_exit(void);
void free_resources(t_list **stack, char **split);
int ft_isspace(char c);
long ft_atol(const char *str);

/* stack manipulation */
void init_stack_null(t_list **stack_a, t_list **stack_b);
t_list *split_and_push(char *str, t_list *stack);
t_list *create_node(int data);
t_list *push_numbers_to_stack(char *str, t_list *stk);

/* argument parsing and validation */
t_list *handle_arguments(int argc, char **argv);
void validate_and_push(char *token, t_list **stack,
                       char **split);
bool check_duplicates(t_list *stack, int num);
bool is_valid_input(char *str);
void append_node(t_list **stack, int num);

/* stack sorting */
bool stack_sorted(t_list *stk);
void sort_three(t_list **stk);
void sa(t_list **stk, bool print);
void turk_algorithm(t_list **stk_a, t_list **stk_b);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_and_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:12:29 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/26 18:05:20 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* if the numbers are as "SINGLE STRING" argv[1] split the string
and push them into the stack_a

    -- Handle integer overflows, duplicates, and sytax errors, (input must only
    contains digits, '+' or '-' signs if errors found, free stack A and return
    error)
    -- Check for each input if it's a long integer, if it is convert it into
    a long integer

if everything is good append the numbers as nodes to the stack_a */
t_list *split_and_push(char *str, t_list *stack_a)
{
    printf("\t🔧 [RUNNING] Arguments is a single string, running split_and_push function\n");
    char **split;
    int i;
    long num;

    split = ft_split(str, ' ');
    if (!split)
        error_exit();
    i = 0;
    while (split[i])
    {
        validate_and_push(split[i], &stack_a, split);
        i++;
    }
    free_resources(NULL, split);
    printf("\t🔧 [ENDING] split_and_push function\n");
    return (stack_a);
}

void validate_and_push(char *token, t_list **stack, char **split)
{
    printf("\t\t🔧 [RUNNING] validate_and_push function\n");
    long num;

    /* validate the input syntax */
    if (!is_valid_input(token))
    {
        free_resources(stack, split);
        error_exit();
    }
    /* convert to long and check for integer overflows */
    num = ft_atol(token);
    if (num > INT_MAX || num < INT_MIN)
    {
        free_resources(stack, split);
        error_exit();
    }
    /* check for duplicates */
    if (check_duplicates(*stack, (int)num))
    {
        free_resources(stack, split);
        error_exit();
    }
    printf("\t\t🔧 [ENDING] validate_and_push function\n");
}

bool check_duplicate(t_list *stack, int num)
{
    while (stack)
    {
        if (stack->data == num)
            return (true);
        stack = stack->next;
    }
    return (false);
}

void append_node(t_list **stack, int num)
{
    t_list *new_node;

    new_node = malloc(sizeof(t_list));
    if (!new_node)
    {
        free_stack(stack);
        error_exit();
    }
    new_node->data = num;
    new_node->index = -1;
    new_node->push_cost = 0;
    new_node->above_median = false;
    new_node->cheapest = false;
    new_node->target_node = NULL;
    new_node->next = *stack;
    new_node->prev = NULL;
    if (*stack)
        (*stack)->prev = new_node;
    *stack = new_node;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_and_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:12:29 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/21 18:01:43 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool is_valid_input(char *str)
{
    int i;

    i = 0;
    if (!str || !str[i])
        return (false);
    if (str[i] == '-' || str[i] == '+')
        i++;
    if (!str[i])
        return (false);
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (false);
        i++;
    }
    return (true);
}
t_list *split_and_push(char *str, t_list *stack)
{
    int i;
    char **numbers;

    i = 0;
    numbers = ft_split(str, ' ');
    if (!numbers)
        error_exit();
    while (numbers[i])
    {
        if (!is_valid_input(numbers[i]))
        {
            free_split(numbers);
            free_stack(&stack);
            error_exit();
        }
        stack = push_numbers_to_stack(numbers[i], stack);
        free(numbers[i]);
        i++;
    }
    free(numbers);
    return (stack);
}

t_list *push_numbers_to_stack(char *str, t_list *stk)
{
    long num;
    t_list *new_node;

    num = ft_atoi(str);
    if (num < INT_MIN || num > INT_MAX)
    {
        free_stack(&stk);
        error_exit();
    }
    new_node = create_node((int)num);
    if (!new_node)
    {
        free_stack(&stk);
        error_exit();
    }
    new_node->next = stk;
    if (stk)
        stk->prev = new_node;
    return (new_node);
}

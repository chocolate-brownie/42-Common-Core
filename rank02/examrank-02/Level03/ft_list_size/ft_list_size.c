/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:43:03 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/20 13:48:16 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list_size.h"

int ft_list_size(t_list *begin_list)
{
    int count = 0;
    while (begin_list)
    {
        begin_list = begin_list->next;
        count++;
    }
    return count;
}

#include <stdio.h>
#include <stdlib.h>

t_list *create_node(void *data)
{
    t_list *node = (t_list *)malloc(sizeof(t_list));
    if (!node)
        return NULL;
    node->data = data;
    node->next = NULL;
    return node;
}

int main(void)
{
    t_list *head = create_node("Node 1");
    head->next = create_node("Node 2");
    head->next->next = create_node("Node 3");

    printf("List size is %d\n", ft_list_size(head));
    return 0;
}
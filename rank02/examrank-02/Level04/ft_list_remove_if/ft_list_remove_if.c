/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:35:29 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/07 19:55:04 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    /* We need to handle the head node separately
    in case it needs to be removed. */
    t_list *to_delete;

    /* removing matching HEAD node at the beginning of the list */
    while (*begin_list && cmp((*begin_list)->data, data_ref) == 0)
    {
        to_delete = *begin_list;
        *begin_list = (*begin_list)->next;
        free(to_delete);
    }

    /* initializing the current point to the head of the list */
    t_list *current = *begin_list;
    while (current && current->next)
    {
        if (cmp(current->next->data, data_ref) == 0)
        {
            to_delete = current->next;
            current->next = current->next->next;
            free(to_delete);
        }
        else
            current = current->next;
    }
}
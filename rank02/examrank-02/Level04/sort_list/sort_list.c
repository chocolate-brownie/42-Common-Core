/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:31:29 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/08 15:52:37 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_list.h"
#include <stdlib.h>

t_list *sort_list(t_list *lst, int (*cmp)(int, int))
{
    t_list *start = lst;
    while (lst && lst->next)
    {
        if ((*cmp)(lst->data, lst->next->data) == 0)
        {
            int swap = lst->data;
            lst->data = lst->next->data;
            lst->next->data = swap;

            lst = start;
        }
        else
        {
            lst = lst->next;
        }
    }
    return start;
}
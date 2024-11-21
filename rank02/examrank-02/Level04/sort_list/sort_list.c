/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:08:32 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/21 12:11:32 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_list t_list;
struct s_list
{
    int data;
    t_list *next;
};

#include <stdlib.h>

t_list *sort_list(t_list *lst, int (*cmp)(int, int))
{
    t_list *start = lst;
    int swap;

    while (!lst && !lst->next)
    {
        if ((*cmp)(lst->data, lst->next->data) == 0)
        {
            swap = lst->data;
            lst->data = lst->next->data;
            lst->next->data = swap;

            lst = start;
        }
        else
            lst = lst->next;
    }
    return start;
}
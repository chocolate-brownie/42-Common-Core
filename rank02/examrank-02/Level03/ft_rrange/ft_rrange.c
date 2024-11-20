/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:54:43 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/20 13:59:30 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int *ft_rrange(int start, int end)
{
    int size = 0;
    if (start <= end)
        size = end - start + 1;
    else
        size = start - end + 1;

    int *tab = (int *)malloc(sizeof(int) * size);
    if (!tab)
        return NULL;

    int i = 0;
    while (i < size)
    {
        if (start <= end)
            tab[i] = end - i;
        else
            tab[i] = end + i;
        i++;
    }
    return tab;
}
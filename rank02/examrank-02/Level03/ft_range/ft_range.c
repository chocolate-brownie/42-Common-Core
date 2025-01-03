/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:48:33 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/20 13:53:35 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int *ft_range(int start, int end)
{
    int size = 0;
    if (start <= end)
        size = end - start + 1;
    else
        size = start - end + 1;

    int *tab = (int *)malloc(sizeof(int) * (size));
    if (!tab)
        return NULL;

    int i = 0;
    while (i < size)
    {
        if (start <= end)
            tab[i] = start + i;
        else
            tab[i] = start - i;
        i++;
    }
    return tab;
}
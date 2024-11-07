/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:33:27 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/07 15:38:37 by mgodawat         ###   ########.fr       */
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

    int *range = (int *)malloc(sizeof(int) * size);
    if (!range)
        return NULL;

    int i = 0;
    while (i < size)
    {
        if (start <= end)
            range[i] = end - i;
        else
            range[i] = end + i;
        i++;
    }
    return range;
}

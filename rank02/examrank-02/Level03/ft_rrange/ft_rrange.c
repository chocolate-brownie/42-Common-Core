/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:32:25 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/04 16:35:26 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int     *ft_rrange(int start, int end)
{
    int size = 0;
    if (start <= end)
        size = end - start + 1;
    else
        size = start - end + 1;
    
    int *array = (int *)malloc(sizeof(int));
    if (!array)
        return NULL;

    int i = 0;
    while (i < size)
    {
        if (start <= end)
            array[i] = end - i;
        else
            array[i] = end + i;
        
        i++;
    }
    return array;
}
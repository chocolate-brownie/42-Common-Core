/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:27:41 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/04 16:31:41 by mgodawat         ###   ########.fr       */
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

    int *array = (int *)malloc(size * (sizeof(int)));
    if (!array)
        return NULL;
    
    int i = 0;
    while (i < size)
    {
        if (start <= end)
            array[i] = start + i;
        else
            array[i] = start - i;
        i++;
    }       
    return array; 
}
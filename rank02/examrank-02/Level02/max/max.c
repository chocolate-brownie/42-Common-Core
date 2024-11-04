/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:53:51 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/04 12:03:04 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		max(int* tab, unsigned int len)
{
    if (len == 0)
        return 0;

    int max = tab[0];

    int i = 1;
    while (i < len)
    {
        if (tab[i] > max)
            max = tab[i];
        i++;
    }
    return max;
}

#include <stdio.h>

int main(void) 
{
    int array1[] = {3, 5, 7, 2, 8};
    printf("Max of array1: %d\n", max(array1, 5));  
    return 0;
}

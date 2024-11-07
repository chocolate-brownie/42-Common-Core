/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:22:05 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/07 19:29:12 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int numlen(int nbr)
{
    int count = 0;
    if (nbr <= 0)
        count = 1;
    while (nbr != 0)
    {
        nbr /= 10;
        count++;
    }
    return count;
}

char *ft_itoa(int nbr)
{
    int len = numlen(nbr);
    char *str = (char *)malloc(sizeof(char) * (len + 1));
    if (!str)
        return NULL;

    int isneg = 0;
    str[len] = '\0';
    if (nbr < 0)
    {
        nbr = -nbr;
        isneg = 1;
    }

    if (nbr == 0)
        str[0] = '0';

    while (nbr != 0)
    {
        str[--len] = (nbr % 10) + '0';
        nbr /= 10;
    }
    if (isneg)
        str[0] = '-';
    return str;
}
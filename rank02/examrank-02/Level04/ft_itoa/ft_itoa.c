/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:41:28 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/04 19:54:29 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int ft_intlen(int nbr)
{
    int len = 0;
    if (nbr == 0)
        return 1;
    // if neg add 1 for the '-'
    if (nbr < 0)
        len++;

    while (nbr != 0)
    {
        nbr /= 10;
        len++;
    }
    return len;
}

char *ft_itoa(int nbr)
{
    int len = ft_intlen(nbr);
    char *str = (char *)malloc(len + 1);

    if (!str)
        return NULL;

    str[len] = '\0';
    if (nbr == 0)
    {
        str[0] = '0';
        return str;
    }

    int is_neg = nbr < 0;
    unsigned int num = is_neg ? -nbr : nbr;

    while (num > 0)
    {
        str[--len] = (num % 10) + '0';
        num /= 10;
    }

    if (is_neg)
        str[0] = '-';
    return str;
}

#include <stdio.h>

int main()
{
    printf("123: %s\n", ft_itoa(123));
    printf("-456: %s\n", ft_itoa(-456));
    printf("0: %s\n", ft_itoa(0));
    printf("-2147483648: %s\n", ft_itoa(-2147483648)); // Min int value

    return 0;
}

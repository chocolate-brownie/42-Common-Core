/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:51:15 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/21 10:55:40 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int ft_intlen(int nbr)
{
    int count = 0;
    if (nbr <= 0)
        count++;
    while (nbr != 0)
    {
        nbr /= 10;
        count++;
    }
    return count;
}

char *ft_itoa(int nbr)
{
    int len = ft_intlen(nbr);
    char *str = (char *)malloc(sizeof(char) * (len + 1));
    if (!str)
        return NULL;

    str[len] = '\0';
    unsigned int num = 0;

    if (nbr < 0)
        num = -nbr;
    else
        num = nbr;

    while (len--)
    {
        str[len] = (num % 10) + '0';
        num /= 10;
    }
    if (nbr < 0)
        str[0] = '-';

    return str;
}

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("%s\n", ft_itoa(12345));       // Output: "12345"
    printf("%s\n", ft_itoa(-12345));      // Output: "-12345"
    printf("%s\n", ft_itoa(0));           // Output: "0"
    printf("%s\n", ft_itoa(-2147483648)); // Output: "-2147483648"

    return 0;
}

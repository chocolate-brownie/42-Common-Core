/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:57:23 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/19 21:18:05 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int char_to_value(char c)
{
    if (c >= '0' && c <= '9')
        return c - '0';
    if (c >= 'a' && c <= 'f')
        return c - 'a' + 10;
    if (c >= 'A' && c <= 'F')
        return c - 'A' + 10;
    return -1; // invalid character
}

int ft_atoi_base(char *str, int str_base)
{
    int res = 0;
    int sign = 1;

    if (str_base < 2 || str_base > 16)
        return 0;

    while (*str == ' ' || (*str >= 9 && *str <= 13))
        str++;

    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }

    int value;
    while (*str)
    {
        value = char_to_value(*str);
        if (value < 0 || value >= str_base)
            break;
        res = res * str_base + value;
        str++;
    }
    return res * sign;
}

int main(void)
{
    printf("%d\n", ft_atoi_base("   -1a", 16)); // Expected: -26
    printf("%d\n", ft_atoi_base("1010", 2));    // Expected: 10
    printf("%d\n", ft_atoi_base("7b", 16));     // Expected: 123
}
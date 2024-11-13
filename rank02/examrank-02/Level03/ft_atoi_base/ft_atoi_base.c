/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milan-godawatta <milan-godawatta@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:28:33 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/13 17:45:25 by milan-godaw      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int is_valid(char c)
{
    if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))
        return (1);
    return (0);
}

int char_to_value(char c)
{
    if (c >= '0' && c <= '9')
        return (c - '0');
    if (c >= 'A' && c <= 'F')
        return (c - 'A' + 10);
    if (c >= 'a' && c <= 'f')
        return (c - 'a' + 10);
    return (0);
}

int ft_atoi_base(const char *str, int str_base)
{
    int i;
    int value;
    int result;
    int sign;

    result = 0;
    sign = 1;
    i = 0;
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] && is_valid(str[i]))
    {
        value = char_to_value(str[i]);
        if (value >= str_base)
            break;
        result = result * str_base + value;
        i++;
    }
    return (result * sign);
}

int main(void)
{
    const char *test1 = "   -1a";
    const char *test2 = "  101";
    const char *test3 = "7F";
    const char *test4 = "42";
    const char *test5 = "   +1A3F";
    const char *test6 = "   123abc";
    const char *test7 = "   -2A3";
    const char *test8 = "1111";

    printf("Base 16, Input \"%s\" -> Result: %d\n", test1, ft_atoi_base(test1, 16));
    printf("Base 2, Input \"%s\" -> Result: %d\n", test2, ft_atoi_base(test2, 2));
    printf("Base 16, Input \"%s\" -> Result: %d\n", test3, ft_atoi_base(test3, 16));
    printf("Base 10, Input \"%s\" -> Result: %d\n", test4, ft_atoi_base(test4, 10));
    printf("Base 16, Input \"%s\" -> Result: %d\n", test5, ft_atoi_base(test5, 16));
    printf("Base 10, Input \"%s\" -> Result: %d\n", test6, ft_atoi_base(test6, 10));
    printf("Base 16, Input \"%s\" -> Result: %d\n", test7, ft_atoi_base(test7, 16));
    printf("Base 2, Input \"%s\" -> Result: %d\n", test8, ft_atoi_base(test8, 2));
    return (0);
}

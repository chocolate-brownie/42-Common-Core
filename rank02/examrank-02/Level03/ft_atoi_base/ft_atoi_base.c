/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:40:55 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/04 15:56:49 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int is_valid_char(char c, int base)
{
    if (c >= '0' && c <= '9')
        return (c - '0' < base);
    if (c >= 'a' && c <= 'f')
        return (10 + c - 'a' < base);
    if (c >= 'A' && c <= 'F')
        return (10 + c - 'A' < base);
    return 0;
}

int char_to_value(char c)
{
    if (c >= '0' && c <= '9')
        return (c - '0');
    if (c >= 'a' && c <= 'f')
        return (10 + c - 'a');
    if (c >= 'A' && c <= 'F')
        return (10 + c - 'A');
    return 0;
}

int	ft_atoi_base(const char *str, int str_base)
{
    int sign = 1;
    int result = 0;
    int i = 0;

    while (str[i] == ' ' || str[i] >= 9 && str[i] <= 13)
        i++;
    
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    
    while (str[i])
    {
        if (!is_valid_char(str[i], str_base))
            break;
        
        result = result * str_base + char_to_value(str[i]);
        i++;
    }
    return sign * result;

    
}

#include <stdio.h>

int	main(void)
{
	// Test cases
	const char *test1 = "12fdb3";
	const char *test2 = "-1010";
	const char *test3 = "ff";
	const char *test4 = "123";
	const char *test5 = "7f";
	const char *test6 = "-1a";
	const char *test7 = "zzz";   // Invalid for any base <= 16

	// Testing ft_atoi_base
	printf("Testing base 16:\n");
	printf("Input: \"%s\", Base: 16, Result: %d\n", test1, ft_atoi_base(test1, 16));
	printf("Input: \"%s\", Base: 2, Result: %d\n", test2, ft_atoi_base(test2, 2));
	printf("Input: \"%s\", Base: 16, Result: %d\n", test3, ft_atoi_base(test3, 16));
	printf("Input: \"%s\", Base: 10, Result: %d\n", test4, ft_atoi_base(test4, 10));
	printf("Input: \"%s\", Base: 16, Result: %d\n", test5, ft_atoi_base(test5, 16));
	printf("Input: \"%s\", Base: 16, Result: %d\n", test6, ft_atoi_base(test6, 16));
	printf("Input: \"%s\", Base: 36 (Invalid base)\n", test7);

	return 0;
}

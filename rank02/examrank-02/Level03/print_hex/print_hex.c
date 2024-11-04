/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:08:14 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/04 17:24:46 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_atoi(char *str)
{
    int i = 0;
    int result = 0;

    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return 0;
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return result;
}

void ft_puthex(int n)
{
    char hex_digits[] = "0123456789abcdef";
    if (n >= 16)
        ft_puthex(n / 16);
    write(1, &hex_digits[n % 16], 1);
}

int main(int argc, char **argv)
{
    if (argc == 2)
        ft_puthex(ft_atoi(argv[1]));
    write(1, "\n", 1);
}
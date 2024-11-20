/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:38:57 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/20 14:46:41 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void print_hex(int nbr)
{
    char *hex_digits = "0123456789abcdef";
    if (nbr >= 16)
        print_hex(nbr / 16);
    write(1, &hex_digits[nbr % 16], 1);
}

int ft_atoi(char *str)
{
    int res = 0;
    while (*str)
    {
        res = res * 10 + (*str - '0');
        str++;
    }
    return res;
}

int main(int argc, char *argv[])
{
    if (argc == 2)
        print_hex(ft_atoi(argv[1]));
    write(1, "\n", 1);
    return 0;
}

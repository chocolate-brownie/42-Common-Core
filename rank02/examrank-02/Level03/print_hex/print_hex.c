/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:24:08 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/07 16:30:51 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_puthex(int nbr) {
    char hex_digit[] = "0123456789abcdef";
    if (nbr >= 16)
        ft_puthex(nbr / 16);
    write(1, &hex_digit[nbr % 16], 1);
}

int ft_atoi(char *str) {
    int res = 0;
    int i = 0;
    while (str[i]) {
        res = res * 10 + (str[i] - '0');
        i++;
    }
    return res;
}

int main(int argc, char **argv) {
    if (argc == 2) {
        int num = ft_atoi(argv[1]);
        ft_puthex(num);
    }
    write(1, "\n", 1);
    return 0;
}

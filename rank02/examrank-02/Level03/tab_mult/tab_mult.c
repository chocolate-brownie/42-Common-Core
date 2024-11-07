/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:03:11 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/07 17:13:15 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putnbr(int num) {
    if (num >= 10)
        ft_putnbr(num / 10);
    char digit = num % 10 + '0';
    write(1, &digit, 1);
}

int ft_atoi(char *str) {
    int res = 0;
    int sign = 1;

    int i = 0;
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;

    if (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-')
            sign = -1;
        i++;
    }

    while (str[i] >= '0' && str[i] <= '9') {
        res = res * 10 + (str[i] - '0');
        i++;
    }
    return res * sign;
}

int main(int argc, char **argv) {
    if (argc == 2) {
        int num = ft_atoi(argv[1]);
        int i = 1;
        while (i <= 9) {
            ft_putnbr(i);
            write(1, " x ", 3);
            ft_putnbr(num);
            write(1, " = ", 3);
            ft_putnbr(i * num);
            write(1, "\n", 1);
            i++;
        }
    }
    else {
        write(1, "\n", 1);
    }
    return 0;
}

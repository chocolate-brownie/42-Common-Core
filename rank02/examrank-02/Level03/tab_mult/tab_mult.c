/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:38:00 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/20 17:50:24 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putnbr(int nbr)
{
    if (nbr >= 10)
        ft_putnbr(nbr / 10);
    char digit = nbr % 10 + '0';
    write(1, &digit, 1);
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

void tab_mult(int nbr)
{
    int i = 1;
    while (i <= 9)
    {
        ft_putnbr(i);
        write(1, " x ", 3);
        ft_putnbr(nbr);
        write(1, " = ", 3);
        ft_putnbr(i * nbr);
        write(1, "\n", 1);
        i++;
    }
}

int main(int argc, char *argv[])
{
    if (argc == 2)
        tab_mult(ft_atoi(argv[1]));
    else
        write(1, "\n", 1);
    return 0;
}
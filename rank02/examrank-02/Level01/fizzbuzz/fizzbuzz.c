/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:36:18 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/18 15:42:25 by mgodawat         ###   ########.fr       */
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

void ft_putstr(char *str)
{
    unsigned int i = 0;
    while (str[i])
        write(1, &str[i++], 1);
}

int main(void)
{
    int i = 0;
    while (++i <= 100)
    {
        if (i % 15 == 0)
            ft_putstr("fizzbuzz");
        else if (i % 3 == 0)
            ft_putstr("fizz");
        else if (i % 5 == 0)
            ft_putstr("buzz");
        else
            ft_putnbr(i);
        ft_putstr("\n");
    }
}
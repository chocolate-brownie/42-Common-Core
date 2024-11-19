/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:50:43 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/19 20:05:01 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_isprime(int nbr)
{
    if (nbr < 2)
        return 0;
    int i = 2;
    while (i <= nbr / 2)
    {
        if (nbr % i == 0)
            return 0;
        i++;
    }
    return 1;
}

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
    int i = 0;
    while (str[i])
    {
        res = res * 10 + (str[i] - '0');
        i++;
    }
    return res;
}

void add_prime_sum(int nbr)
{
    int sum = 0;
    while (nbr--)
    {
        if (ft_isprime(nbr))
            sum += nbr;
    }
    ft_putnbr(sum);
}

int main(int argc, char *argv[])
{
    if (argc == 2)
        add_prime_sum(ft_atoi(argv[1]));
    write(1, "\n", 1);
    return 0;
}
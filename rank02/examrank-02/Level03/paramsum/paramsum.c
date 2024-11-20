/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:27:20 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/20 14:30:40 by mgodawat         ###   ########.fr       */
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

int main(int argc, char *argv[])
{
    (void)argv;
    ft_putnbr(argc - 1);
    write(1, "\n", 1);
    return 0;
}
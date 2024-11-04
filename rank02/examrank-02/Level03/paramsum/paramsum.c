/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:52:31 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/04 16:59:44 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putnbr(int num)
{
    if (num >= 10)
        ft_putnbr(num / 10);
    char digit = num % 10 + '0';
    write(1, &digit, 1);
}

int main(int argc, char **argv)
{
    (void)argv;
    
    ft_putnbr(argc - 1);
    write(1, "\n", 1);
    return 0;
}
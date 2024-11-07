/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:02:13 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/07 19:03:50 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int ft_isprime(int num)
{
    int i = 2;
    if (num < 2)
        return 0;
    while (i * i <= num)
    {
        if (num % i == 0)
            return 0;
        i++;
    }
    return 1;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        write(1, "\n", 1);
        return 0;
    }
    else
    {
        int num = atoi(argv[1]);
        int flag = 1;
        if (num < 1)
        {
            printf("\n");
            return 0;
        }
        if (num == 1)
        {
            printf("1\n");
            return 0;
        }
        int factor = 2;
        while (num > 1)
        {
            if (ft_isprime(factor))
            {
                if (!flag)
                    printf("*");
                printf("%d", factor);
                num /= factor;
                flag = 0;
            }
            factor++;
        }
    }
    printf("\n");
    return 0;
}
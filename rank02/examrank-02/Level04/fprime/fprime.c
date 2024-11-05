/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:30:52 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/04 19:41:04 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void fprime(int num)
{
    if (num == 1)
    {
        printf("1\n");
        return;
    }

    int factor = 2;
    while (factor <= num)
    {
        if (num % factor == 0)
        {
            printf("%d", factor);
            num /= factor;
            if (num > 1)
                printf("*");
        }
        else
            factor++;
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        int num = atoi(argv[1]);
        if (num > 0)
            fprime(num);
        else
            printf("\n");
    }
    else
        printf("\n");
    return 0;
}
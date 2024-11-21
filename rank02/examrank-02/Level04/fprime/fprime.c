/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:45:33 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/21 10:51:01 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void fprime(int nbr)
{
    int factor = 2;
    if (nbr == 1)
    {
        printf("1\n");
        return;
    }

    while (nbr > 1)
    {
        if (nbr % factor == 0)
        {
            printf("%d", factor);
            nbr /= factor;
            if (nbr > 1)
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
        fprime(atoi(argv[1]));
    else
        printf("\n");
    return 0;
}
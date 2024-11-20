/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:32:26 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/20 14:38:22 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

unsigned int gcd(unsigned int a, unsigned int b)
{
    while (b != 0)
    {
        unsigned int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main(int argc, char *argv[])
{
    if (argc == 3)
        printf("%d", gcd(atoi(argv[1]), atoi(argv[2])));
    printf("\n");
    return 0;
}
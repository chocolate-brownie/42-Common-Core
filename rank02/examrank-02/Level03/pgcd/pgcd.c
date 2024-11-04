/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:00:00 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/04 17:07:46 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

unsigned int gcd(int a, int b)
{
    while (b != 0)
    {
        unsigned int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("\n");
        return 0;
    }

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    
    printf("%d\n", gcd(a, b));
    return 0;
}
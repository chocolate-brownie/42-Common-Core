/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:08:13 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/20 14:26:12 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

unsigned int lcm(unsigned int a, unsigned int b)
{
    if (a == 0 || b == 0)
        return 0;
    return (a / gcd(a, b)) * b;
}

#include <stdio.h>

int main()
{
    printf("LCM of 12 and 18: %u\n", lcm(12, 18)); // Expected: 36
    printf("LCM of 7 and 3: %u\n", lcm(7, 3));     // Expected: 21
    printf("LCM of 0 and 18: %u\n", lcm(0, 18));   // Expected: 0
    printf("LCM of 4 and 5: %u\n", lcm(4, 5));     // Expected: 20
    return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:45:17 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/04 16:50:46 by mgodawat         ###   ########.fr       */
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

unsigned int    lcm(unsigned int a, unsigned int b)
{
    if (a == 0 || b == 0)
        return 0;
    
    return (a / gcd(a, b)) * b;
}


#include <stdio.h>

int main(void)
{
    printf("%d", lcm(4, 5));    
}
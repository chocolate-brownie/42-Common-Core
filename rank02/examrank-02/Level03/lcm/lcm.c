/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:59:08 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/07 16:08:22 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int gcd(unsigned int a, unsigned int b) {
    while (b != 0) {
        unsigned int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

unsigned int lcm(unsigned int a, unsigned int b) {
    if (a == 0 || b == 0)
        return 0;
    return (a / gcd(a, b)) * b;
}

int main(void) {
    unsigned int a = 12;
    unsigned int b = 18;

    printf("LCM of %u and %u is %u\n", a, b, lcm(a, b));

}

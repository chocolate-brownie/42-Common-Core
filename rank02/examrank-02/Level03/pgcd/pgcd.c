/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:16:52 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/07 16:22:11 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

unsigned int gcd(unsigned int a, unsigned int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main(int argc, char *argv[]) {

    if (argc == 3) {
        int a = atoi(argv[1]);
        int b = atoi(argv[2]);

        if (a <= 0 || b <= 0) {
            printf("\n");
            return 0;
        }

        printf("%d\n", gcd(a, b));
    } else {
        printf("\n");
        return 0;
    }
}

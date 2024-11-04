/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:36:23 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/04 12:48:40 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void print_bits(unsigned char octet)
{
    unsigned char mask = 128;
    
    while (mask > 0)
    {
        if (mask & octet)
            write(1, "1", 1);
        else
            write(1, "0", 1);
        mask = mask >> 1;
    }
}

unsigned char reverse_bits(unsigned char octet)
{
    unsigned char reversed = 0;
    int i = 8;

    while (i--)
    {
        reversed = (reversed << 1) | (octet & 1);
        octet = octet >> 1;
    }
    return reversed;
}

#include <stdio.h>

int main(void)
{
    print_bits(2);
    printf("\n");
    unsigned char rever = reverse_bits(2);
    print_bits(rever);
}
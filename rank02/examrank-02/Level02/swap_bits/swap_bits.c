/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:49:37 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/04 13:00:09 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void print_bits(unsigned char octet) 
{
    unsigned char mask = 128;
    
    while (mask > 0)
    {
        if (octet & mask)
            write(1, "1", 1);
        else
            write(1, "0", 1);
        
        mask = mask >> 1;
    }
}

unsigned char reversed_bits(unsigned char octet)
{
    unsigned char rev_bit = 0;
    int i = 8;

    while (i--)
    {
        rev_bit = (rev_bit << 1) | (octet & 1);
        octet = octet >> 1;
    }
    return rev_bit;
}

unsigned char swap_bits(unsigned char octet)
{
    return (octet >> 4) | (octet << 4);
}

int main(void)
{
    unsigned char octet = 12;
    print_bits(octet);
    printf("\n");
    
    unsigned char swapped = swap_bits(octet);
    print_bits(swapped);
    printf("\n");

    unsigned char reversed = reversed_bits(octet);
    print_bits(reversed);
    printf("\n"); 
}
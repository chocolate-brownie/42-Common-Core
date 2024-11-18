/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 22:25:35 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/18 22:27:52 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void print_bits(unsigned char octet)
{
    unsigned int i = 8;
    char bits;
    while (i--)
    {
        bits = (octet >> i & 1) + '0';
        write(1, &bits, 1);
    }
}

int main(void)
{
    unsigned char octet = 2;
    print_bits(octet);
}
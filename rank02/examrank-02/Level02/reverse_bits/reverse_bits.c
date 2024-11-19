/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:53:17 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/19 16:06:38 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char reverse_bits(unsigned char octet)
{
    unsigned int i = 8;
    unsigned char bits;

    while (i--)
    {
        bits = (bits << 1) | (octet & 1);
        octet = octet >> 1;
    }
    return bits;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:11:14 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/04 11:20:24 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	int i = 0;
	int k;
	

    while (s[i])
    {
        int found = 0;
        k = 0;
        while (accept[k])
        {
            if (s[i] == accept[k])
            {
                found = 1;
                break;
            }
            k++;
        }
        if (!found)
            break;
        i++;
    }
    return i;
}

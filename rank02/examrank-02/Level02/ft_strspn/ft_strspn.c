/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:20:12 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/18 20:30:37 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t ft_strspn(const char *s, const char *accept)
{
    int i = 0;
    int j;
    while (s[i])
    {
        j = 0;
        while (accept[j])
        {
            if (s[i] == accept[j])
                break;
            j++;
        }
        if (accept[j] == '\0')
            return i;
        i++;
    }
    return i;
}

#include <stdio.h>
#include <string.h>

int main(void)
{
    const char *s = "123abc456";
    const char *accept = "1234567890";

    size_t result1 = strspn(s, accept);
    size_t result2 = ft_strspn(s, accept);

    printf("%ld\n", result1);
    printf("%ld\n", result2);
    return 0;
}
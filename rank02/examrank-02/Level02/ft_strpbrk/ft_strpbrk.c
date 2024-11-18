/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:36:33 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/18 20:39:45 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char *ft_strpbrk(const char *s1, const char *s2)
{
    int i = 0;
    int j;

    while (s1[i])
    {
        j = 0;
        while (s2[j])
        {
            if (s1[i] == s2[j])
                return (char *)&s1[i];
            j++;
        }
        i++;
    }
    return NULL;
}
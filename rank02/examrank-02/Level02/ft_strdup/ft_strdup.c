/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:30:53 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/18 20:36:22 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char *ft_strdup(char *src)
{
    int len = 0;
    while (src[len])
        len++;

    char *dest = (char *)malloc(len + 1);
    if (!dest)
        return NULL;

    int i = 0;
    while (src[i])
        dest[i] = src[i++];
    dest[i] = '\0';
    return dest;
}
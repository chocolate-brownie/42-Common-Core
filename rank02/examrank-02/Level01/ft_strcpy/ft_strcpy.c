/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:43:43 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/18 15:46:58 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_strcpy(char *s1, char *s2)
{
    unsigned int i = 0;
    while (s2[i])
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
    return s1;
}

#include <stdio.h>
#include <string.h>

int main(void)
{
    char *src = "Hello World";
    char dest[strlen(src)];

    printf("%s", ft_strcpy(dest, src));
}
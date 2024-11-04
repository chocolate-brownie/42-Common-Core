/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:29:01 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/04 11:02:15 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char    *ft_strdup(char *src)
{
	int len = 0;
	while (src[len])
		len++;
	
	int i = 0;
	char *dest = (char *)malloc(len + 1);
	if (!dest)
		return NULL;
	
	while (src[i]) {
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return dest;
}

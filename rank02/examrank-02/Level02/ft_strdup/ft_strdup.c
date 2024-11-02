/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:32:46 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/02 17:39:52 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return i;
}

char    *ft_strdup(char *src)
{
	int len = ft_strlen(src);

	char *dest = (char *)malloc(len + 1);
	if (!dest)
		return NULL;
	
	int i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return dest;
}

#include <stdio.h>

int main(void)
{
	char *dest = ft_strdup("Hello World\n");
	printf("%s", dest);
}

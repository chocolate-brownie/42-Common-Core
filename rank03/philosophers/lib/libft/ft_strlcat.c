/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:37:07 by mgodawat          #+#    #+#             */
/*   Updated: 2024/06/04 17:32:59 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * #include <string.h>
 */

size_t	ft_strlcat(char *dst, const char *src, size_t dest_size)
{
	size_t	dst_len;
	size_t	src_len;
	int		i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dest_size == 0)
		return (src_len);
	i = 0;
	while ((dst_len + i < dest_size - 1) && (src[i] != '\0'))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	if (dst_len >= dest_size)
		dst_len = dest_size;
	return (dst_len + src_len);
}

// #include <bsd/string.h>
// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	dst[20] = "Hello, ";
// 	char	src[] = "World!";
// 	size_t	result;
// 	size_t	result2;

// 	result = ft_strlcat(dst, src, 5);
// 	result2 = strlcat(dst, src, 5);
// 	printf("Concatenated string: %s with source: '%s' our=%zu, std=%zu\n", dst,
// 		src, result, result2);
// 	// printf("Total length of the string tried to create: %zu\n", result);
// 	return (0);
// }

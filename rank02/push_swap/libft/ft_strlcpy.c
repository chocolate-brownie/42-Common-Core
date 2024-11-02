/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:52:07 by mgodawat          #+#    #+#             */
/*   Updated: 2024/06/04 15:40:49 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dest_size)
{
	size_t	src_len;
	size_t	counter;

	counter = 0;
	src_len = ft_strlen(src);
	if (dest_size == 0)
		return (src_len);
	while (counter < dest_size - 1 && src[counter] != '\0')
	{
		dest[counter] = src[counter];
		counter++;
	}
	dest[counter] = '\0';
	return (src_len);
}

/*Copy characters from the source to the destination until you
reach the end of the source string or the maximum number of characters
that can fit in the destination buffer (excluding the null terminator).
Ensure that the destination string is null-terminated.
Return the length of the source string. */

/* #include <bsd/string.h>
#include <stdio.h>

void	test(int size)
{
	char	string[] = "Hello there, Venus";
	char	buffer[19];
	int		r;

	r = ft_strlcpy(buffer, string, size);
	printf("Copied '%s' into '%s', length %d\n", string, buffer, r);
}

int	main(void)
{
	// test(19);
	test(10);
	// test(1);
	// test(0);
	return (0);
} */

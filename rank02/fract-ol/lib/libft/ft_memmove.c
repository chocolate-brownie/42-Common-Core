/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:57:19 by mgodawat          #+#    #+#             */
/*   Updated: 2024/06/04 10:40:45 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr_dest;
	unsigned const char	*ptr_src;
	size_t				counter;

	counter = 0;
	if (dest == NULL && src == NULL)
		return (dest);
	ptr_dest = (unsigned char *)dest;
	ptr_src = (unsigned const char *)src;
	if (ptr_dest < ptr_src)
		return (ft_memcpy(dest, src, n));
	if (ptr_dest > ptr_src)
	{
		counter = n;
		while (counter > 0)
		{
			counter--;
			ptr_dest[counter] = ptr_src[counter];
		}
	}
	return (dest);
}

// useful link that helped me
// https://marmota.medium.com/c-language-making-memmove-def8792bb8d5
/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str[] = "Hello, world!";
	char	buffer[20];

	// Use memcpy to copy the string to the buffer
	memcpy(buffer, str + 7, 6);
	printf("Using memcpy: %s\n", buffer);
	// Use memmove to copy the string to the buffer
	ft_memmove(buffer, str + 7, 6);
	printf("Using memmove: %s\n", buffer);
	return (0);
} */

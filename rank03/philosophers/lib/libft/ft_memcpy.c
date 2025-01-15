/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:14:26 by mgodawat          #+#    #+#             */
/*   Updated: 2024/06/04 10:51:03 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*source;
	unsigned char	*destination;
	size_t			counter;

	counter = 0;
	if (src == NULL && dest == NULL)
		return (dest);
	source = (unsigned char *)src;
	destination = (unsigned char *)dest;
	while (counter < n)
	{
		destination[counter] = source[counter];
		counter++;
	}
	return (dest);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	src[] = "Hello World!\n";
// 	char	dest[2];

// 	ft_memcpy(dest, src, 3);
// 	printf("%s\n", dest);
// }

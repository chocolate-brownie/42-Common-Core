/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:04:49 by mgodawat          #+#    #+#             */
/*   Updated: 2024/06/03 17:25:37 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	size_t			counter;

	counter = 0;
	ptr = (unsigned char *)b;
	while (counter < len)
	{
		ptr[counter] = (unsigned char)c;
		counter++;
	}
	return (b);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	word[] = "Hello";

// 	ft_memset(word, 64, 2);
// 	printf("%s\n", word);
// }

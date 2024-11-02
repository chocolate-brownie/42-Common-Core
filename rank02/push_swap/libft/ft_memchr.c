/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:02:31 by mgodawat          #+#    #+#             */
/*   Updated: 2024/06/05 15:53:40 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*string;
	unsigned char		search;
	size_t				counter;

	string = (const unsigned char *)s;
	search = (unsigned char)c;
	counter = 0;
	while (counter < n)
	{
		if (string[counter] == search)
			return ((void *)&string[counter]);
		counter++;
	}
	return (NULL);
}

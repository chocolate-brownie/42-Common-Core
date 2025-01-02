/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:42:01 by mgodawat          #+#    #+#             */
/*   Updated: 2024/06/05 16:52:26 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*string1;
	unsigned char	*string2;
	size_t			counter;

	string1 = (unsigned char *)s1;
	string2 = (unsigned char *)s2;
	counter = 0;
	while (counter < n)
	{
		if (string1[counter] != string2[counter])
			return (string1[counter] - string2[counter]);
		counter++;
	}
	return (0);
}

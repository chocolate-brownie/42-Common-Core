/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 14:28:09 by mgodawat          #+#    #+#             */
/*   Updated: 2024/06/09 15:10:50 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	size_t	index;

	dest = (char *)malloc(ft_strlen(src) + 1);
	if (dest == NULL)
		return (NULL);
	index = 0;
	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

/* Function ft_strdup(input_string: String) -> Pointer to Char
	If input_string is NULL
		Return NULL

	length <- Length of input_string + 1
		// Include space for the null terminator

	Allocate memory of size 'length' and assign it to 'duplicate_string'
	If memory allocation failed
		Return NULL

	WHILE index from 0 to length - 1
		duplicate_string[index] <- input_string[index]

	Return duplicate_string
End Function */

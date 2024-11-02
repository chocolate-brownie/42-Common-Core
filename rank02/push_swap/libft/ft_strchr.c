/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 18:07:53 by mgodawat          #+#    #+#             */
/*   Updated: 2024/06/04 18:44:56 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	counter;
	char			search;

	counter = 0;
	search = (char)c;
	while (s[counter] != '\0')
	{
		if (s[counter] == search)
			return ((char *)&s[counter]);
		counter++;
	}
	if (s[counter] == search)
		return ((char *)&s[counter]);
	return (NULL);
}

// go through the *s
// if find the c -->
// returns a pointer to the first occurence of the specific char
// if the search is '\0' return NULL

/* #include <stdio.h>
#include <string.h>

#define SIZE 40

int	main(void)
{
	char	buffer1[SIZE] = "computer program";
	char	*ptr;
	int		ch;

	ch = 'p';
	ptr = ft_strchr(buffer1, ch);
	printf("The first occurrence of %c in '%s' is '%s'\n", ch, buffer1, ptr);
} */

/*****************  Output should be similar to:  *****************

The first occurrence of p in 'computer program' is 'puter program'
*/

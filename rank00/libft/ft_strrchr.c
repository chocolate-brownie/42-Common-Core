/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 18:50:13 by mgodawat          #+#    #+#             */
/*   Updated: 2024/06/05 14:32:02 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			search;
	unsigned int	len_string;

	len_string = ft_strlen(s);
	search = (char)c;
	while (len_string > 0)
	{
		if (s[len_string] == search)
			return ((char *)&s[len_string]);
		len_string--;
	}
	if (s[len_string] == search)
		return ((char *)&s[len_string]);
	return (NULL);
}

/* #include <stdio.h>
#include <string.h>

// Declare the ft_strrchr function as it would be in your libft.h
char	*ft_strrchr(const char *s, int c);

int	main(void)
{
	const char	*test_str = "Hello, World!";
	char		*result;

	// Test case 1: Character found in the middle
	result = ft_strrchr(test_str, 'o');
	if (result)
		printf("Found 'o' at position: %ld\n", result - test_str);
	else
		printf("'o' not found\n");
	// Test case 2: Character not in the string
	result = ft_strrchr(test_str, 'z');
	if (result)
		printf("Found 'z' at position: %ld\n", result - test_str);
	else
		printf("'z' not found\n");
	// Test case 3: Character is the null terminator
	result = ft_strrchr(test_str, '\0');
	if (result)
		printf("Found null terminator at position: %ld\n", result - test_str);
	else
		printf("Null terminator not found\n");
	return (0);
}
 */

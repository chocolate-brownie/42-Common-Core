/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:27:31 by mgodawat          #+#    #+#             */
/*   Updated: 2024/06/09 16:53:26 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	str_length;
	char	*substring;
	size_t	remaining_lenght;
	size_t	index;

	if (s == NULL)
		return (NULL);
	str_length = ft_strlen(s);
	if (start >= str_length)
		return (ft_strdup(""));
	remaining_lenght = str_length - start;
	if (len > remaining_lenght)
		len = remaining_lenght;
	substring = (char *)malloc(len + 1);
	if (substring == NULL)
		return (NULL);
	index = 0;
	while (index < len && s[start + index] != '\0')
	{
		substring[index] = s[start + index];
		index++;
	}
	substring[index] = '\0';
	return (substring);
}

/* int	main(void)
{
	char	str[] = "Hello, World!";
	char	*sub;

	sub = ft_substr(str, 7, 5);
	if (sub != NULL)
	{
		printf("Substring: %s\n", sub);
		free(sub);
	}
	else
	{
		printf("Failed to allocate memory for substring.\n");
	}
	return (0);
} */

/* Function ft_substr(input_string: String, start: Unsigned Int, length: Size)
	-> Pointer to Char
	// Step 1: Check if the input string is NULL
	If input_string is NULL
		Return NULL

	// Step 2: Calculate the length of the input string
	str_length <- Length of input_string

	// Step 3: Handle case where start is greater than or equal to the string
	length
	If start is greater than or equal to str_length
		// Return an empty string
		Allocate memory for a single character and assign to 'substring'
		Set substring[0] to null terminator
		Return substring

	// Step 4: Adjust length if it exceeds the available characters
	If length is greater than remaining length
		length <- remaining length

	// Step 5: Allocate memory for the new substring
	Allocate memory for 'length + 1' characters and assign to 'substring'
	If memory allocation fails
		Return NULL

	// Step 6: Copy characters from the input string to the substring
	index <- 0
	While index is less than length and input_string[start
		+ index] is not null terminator
		substring[index] <- input_string[start + index]
		Increment index

	// Step 7: Null-terminate the new substring
	Set substring[index] to null terminator

	// Step 8: Return the new substring
	Return substring
End Function */

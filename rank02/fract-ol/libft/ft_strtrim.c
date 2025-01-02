/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:57:10 by mgodawat          #+#    #+#             */
/*   Updated: 2024/06/10 16:37:01 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(const char *s1, const char *set)
{
	const char	*start_index;
	const char	*end_index;
	size_t		len;
	char		*trimmed;

	if (!s1 || !set)
		return (NULL);
	start_index = s1;
	end_index = s1 + ft_strlen(s1) - 1;
	while (*start_index && ft_strchr(set, *start_index))
		start_index++;
	while (end_index > start_index && ft_strchr(set, *end_index))
		end_index--;
	len = end_index - start_index + 1;
	trimmed = (char *)malloc(len + 1);
	if (trimmed == NULL)
		return (NULL);
	ft_strlcpy(trimmed, start_index, len + 1);
	trimmed[len] = '\0';
	return (trimmed);
}

/* #include <stdio.h>

int	main(void)
{
	char	*s1;
	char	*set;
	char	*trimmed;

	s1 = "  Hello, World!  ";
	set = " ";
	trimmed = ft_strtrim(s1, set);
	if (trimmed)
	{
		printf("Original: '%s'\n", s1);
		printf("Trimmed: '%s'\n", trimmed);
		free(trimmed);
	}
	else
	{
		printf("Allocation failed.\n");
	}
	return (0);
} */

/*
The function trims characters specified in a set from both the start and the
end of the given string, creating and returning a new string that excludes
these characters.

1. Check for NULL Inputs: Ensure that neither s1 nor set is NULL.
2. Identify Starting Position: Find the first character in s1
that is not in set.
3. Identify Ending Position: Find the last character in s1 that is not in set.
4. Calculate Length: Determine the length of the substring
that remains after trimming.
5. Allocate Memory: Allocate memory for the new trimmed string.
6. Copy Trimmed Content: Copy the relevant substring from s1 to the new string.
7. Add Null Terminator: Ensure the new string is properly null-terminated.
8. Return the New String: Return the pointer to the trimmed string.
*/

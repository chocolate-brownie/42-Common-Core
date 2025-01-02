/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:34:43 by mgodawat          #+#    #+#             */
/*   Updated: 2024/06/09 17:55:46 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	strlen_total;
	char	*new_string;
	char	*temp;

	if (!s1 || !s2)
		return (NULL);
	strlen_total = ft_strlen(s1) + ft_strlen(s2);
	new_string = (char *)malloc(strlen_total + 1);
	if (!new_string)
		return (NULL);
	temp = new_string;
	while (*s1 != '\0')
		*temp++ = *s1++;
	while (*s2 != '\0')
		*temp++ = *s2++;
	*temp = '\0';
	return (new_string);
}
/*
1. Check for NULL Input: Ensure neither of the input strings is NULL.
2. Calculate Lengths: Compute the lengths of both strings to determine the
	total length of the new string.
3. Allocate Memory: Allocate memory for the new string, including the
	null terminator.
4. Copy First String: Copy all characters from the first string into the
	new string.
5. Copy Second String: Append all characters from the second
	string to the new string.
6. Add Null Terminator: Ensure the new string is properly null-terminated.
7. Return the New String: Return the pointer to the newly created string.
*/

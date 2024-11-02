/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:10:33 by mgodawat          #+#    #+#             */
/*   Updated: 2024/06/08 17:14:15 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	nlen;

	nlen = ft_strlen(needle);
	if (*needle == '\0')
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	while (*haystack != '\0' && len >= nlen)
	{
		if (*haystack == *needle && ft_strncmp(haystack, needle, nlen) == 0)
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}

/* #include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;
	size_t nlen;

	nlen = ft_strlen(needle);
	if (nlen == 0)
		return ((char *)haystack);
	if (len == 0)
		return (NULL);

	i = 0;
	while (haystack[i] != '\0' && i < len)
	{
		if (i + nlen > len)
			break ;

		j = 0;
		while (j < nlen && haystack[i + j] == needle[j])
		{
			if (j == nlen - 1)
				return ((char *)(haystack + i));
			j++;
		}
		i++;
	}
	return (NULL);
} */

/* int	main(void)
{
	size_t		len;
	char		*result;
	const char	*haystack = "Hello, World!";
	const char	*needle = "Wo";

	len = 10;
	result = ft_strnstr(haystack, needle, len);
	if (result != NULL)
	{
		printf("Substring found: %s\n", result);
	}
	else
	{
		printf("Substring not found within the first %zu characters.\n", len);
	}
	return (0);
} */

/*
The function returns a pointer to the first occurrence of the substring in the
original string, or a null pointer if the substring is not found.
*/

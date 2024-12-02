/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:50:56 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/02 17:05:17 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>
#include <stdlib.h>

/* Utility function to check if a character is a delimiter */
static bool	is_delimiter(char c)
{
	return (c == ' ' || c == '\t');
}

/* Counts the number of words in the string */
static int	count_words(const char *s)
{
	int		count;
	bool	in_word;

	count = 0;
	in_word = false;
	while (*s)
	{
		if (!is_delimiter(*s) && !in_word)
		{
			in_word = true;
			count++;
		}
		else if (is_delimiter(*s))
			in_word = false;
		s++;
	}
	return (count);
}

/* Extracts a single word from the string */
static char	*extract_word(const char **s)
{
	const char	*start;
	char		*word;
	int			len;
	int			i;

	len = 0;
	while (**s && is_delimiter(**s))
		(*s)++;
	start = *s;
	while (**s && !is_delimiter(**s))
	{
		len++;
		(*s)++;
	}
	word = (char *)malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

/* Allocates memory for the split array and extracts words */
static char	**allocate_and_extract(const char *s, int words)
{
	char	**result;
	int		i;

	result = (char **)malloc((words + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (i < words)
	{
		result[i] = extract_word(&s);
		if (!result[i])
		{
			while (i > 0)
			{
				i--;
				free(result[i]);
			}
			free(result);
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}

/* Main function to split the string */
char	**ft_split(const char *s)
{
	int	words;

	if (!s)
		return (NULL);
	words = count_words(s);
	return (allocate_and_extract(s, words));
}

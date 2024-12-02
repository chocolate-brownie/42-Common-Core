/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:50:56 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/02 15:58:42 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>
#include <stdlib.h>

static bool	is_delimiter(char c)
{
	return (c == ' ' || c == '\t');
}

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

static char	*extract_word(const char **s)
{
	const char	*start;
	char		*word;
	int			len;

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
	for (int i = 0; i < len; i++)
		word[i] = start[i];
	word[len] = '\0';
	return (word);
}

char	**ft_split(const char *s)
{
	char	**result;
	int		words;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	words = count_words(s);
	result = (char **)malloc((words + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	while (i < words)
	{
		result[i] = extract_word(&s);
		if (!result[i])
		{
			while (i > 0)
				free(result[--i]);
			free(result);
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}

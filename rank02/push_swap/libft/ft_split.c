/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:50:56 by mgodawat          #+#    #+#             */
/*   Updated: 2024/06/11 19:45:11 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	safe_malloc(char **words_v, int position, size_t buffer)
{
	int	index;

	index = 0;
	words_v[position] = malloc(buffer);
	if (words_v[position] == NULL)
	{
		while (index < position)
			free(words_v[index++]);
		return (1);
	}
	return (0);
}

int	fill_words(char **words_v, const char *s, char delimiter)
{
	size_t	len;
	int		index;

	index = 0;
	while (*s != '\0')
	{
		len = 0;
		while (*s == delimiter && *s != '\0')
			++s;
		while (*s != delimiter && *s != '\0')
		{
			++len;
			++s;
		}
		if (len > 0)
		{
			if (safe_malloc(words_v, index, len + 1))
				return (1);
			ft_strlcpy(words_v[index], s - len, len + 1);
			index++;
		}
	}
	words_v[index] = NULL;
	return (0);
}

size_t	count_words(const char *string, char delimiter)
{
	size_t	words;
	int		inside_word;

	words = 0;
	while (*string != '\0')
	{
		inside_word = 0;
		while (*string == delimiter && *string != '\0')
			string++;
		while (*string != delimiter && *string != '\0')
		{
			if (!inside_word)
			{
				words++;
				inside_word = 1;
			}
			string++;
		}
	}
	return (words);
}

char	**ft_split(const char *s, char c)
{
	size_t	words;
	char	**words_vector;

	if (s == NULL)
		return (NULL);
	words = count_words(s, c);
	words_vector = malloc((words + 1) * sizeof(char *));
	if (words_vector == NULL)
		return (NULL);
	if (fill_words(words_vector, s, c))
	{
		free(words_vector);
		return (NULL);
	}
	return (words_vector);
}

/* int	main(void)
{
	char	*string;
	char	**vector;

	string = "     Hello   there, word!!  ";
	vector = ft_split(string, ' ');
	while (*vector)
	{
		printf("%s\n", *vector++);
	}
	return (0);
} */

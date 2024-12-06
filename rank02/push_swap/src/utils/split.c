/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:27:09 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/06 11:37:26 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	count_words(const char *str, const char separator)
{
	int	count;
	int	inside_word;

	count = 0;
	inside_word = 0;
	while (*str)
	{
		if (*str != separator && !inside_word)
		{
			count++;
			inside_word = 1;
		}
		else if (*str == separator)
			inside_word = 0;
		str++;
	}
	return (count);
}

static int	find_next_word(char *str, char delim, int *cursor, int *len)
{
	int	start;

	start = *cursor;
	while (str[start] == delim)
		start++;
	*cursor = start;
	*len = 0;
	while (str[*cursor] != delim && str[*cursor] != '\0')
	{
		(*len)++;
		(*cursor)++;
	}
	return (start);
}

static char	*get_next_word(char *str, char delim, int *cursor)
{
	int		len;
	int		start;
	int		i;
	char	*word;

	len = 0;
	start = find_next_word(str, delim, cursor, &len);
	i = 0;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = str[start + i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

static int	complete_array(char **words, char *str, char delim, int word_count)
{
	int	cursor;
	int	i;

	cursor = 0;
	i = 0;
	words[i] = malloc(sizeof(char));
	if (!words[i])
		return (NULL);
	words[i++][0] = '\0';
	while (i <= word_count)
	{
		words[i] = get_next_word(str, delim, &cursor);
		if (!words[i])
		{
			while (--i >= 0)
				free(words[i]);
			return (0);
		}
	}
	words[i] = NULL;
	return (1);
}

char	**split(char *str, char delimiter)
{
	int		word_count;
	char	**words_array;

	word_count = count_words(str, delimiter);
	words_array = (char **)malloc(sizeof(char *) * (word_count + 2));
	if (!words_array)
		return (NULL);
	if (!complete_array(words_array, str, delimiter, word_count))
	{
		free(words_array);
		return (NULL);
	}
	return (words_array);
}

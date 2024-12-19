/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:42:56 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/19 19:47:15 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	count_string_words(const char *str, char separator)
{
	int		word_count;
	bool	in_word;

	word_count = 0;
	while (*str)
	{
		in_word = false;
		while (*str == separator && *str)
			++str;
		while (*str != separator && *str)
		{
			if (!in_word)
			{
				++word_count;
				in_word = true;
			}
			++str;
		}
	}
	return (word_count);
}

static char	*extract_next_word(const char *str, char separator)
{
	static int	cursor = 0;
	char		*word;
	int			word_len;
	int			i;

	while (str[cursor] == separator)
		++cursor;
	word_len = 0;
	while (str[cursor + word_len] != separator && str[cursor + word_len])
		++word_len;
	word = malloc((size_t)word_len * sizeof(char) + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (str[cursor] != separator && str[cursor])
		word[i++] = str[cursor++];
	word[i] = '\0';
	return (word);
}

static char	**init_input_array(int word_count)
{
	char	**input_array;

	input_array = malloc(sizeof(char *) * (size_t)(word_count + 2));
	if (!input_array)
		return (NULL);
	input_array[0] = malloc(sizeof(char));
	if (!input_array[0])
	{
		free(input_array);
		return (NULL);
	}
	input_array[0][0] = '\0';
	return (input_array);
}

/**
 * Splits input string into array of strings based on separator
 * Creates argv-like structure with empty string at index 0
 *
 * @param str String to split
 * @param separator Character used to separate words
 * @return Array of strings, or NULL if allocation fails
 */
char	**split_input(char *str, char separator)
{
	int		word_count;
	char	**input_array;
	int		i;

	word_count = count_string_words(str, separator);
	if (!word_count)
		exit(EXIT_FAILURE);
	input_array = init_input_array(word_count);
	if (!input_array)
		return (NULL);
	i = 1;
	while (word_count-- > 0)
	{
		input_array[i] = extract_next_word(str, separator);
		if (!input_array[i])
			return (NULL);
		i++;
	}
	input_array[i] = NULL;
	return (input_array);
}

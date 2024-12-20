/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:42:56 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/20 15:29:20 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	get_word_length(const char *str, char separator, int start)
{
	int	len;

	len = 0;
	while (str[start + len] && str[start + len] != separator)
		len++;
	return (len);
}

static char	*extract_word(const char *str, char separator, int *index)
{
	char	*word;
	int		len;
	int		i;

	while (str[*index] == separator)
		(*index)++;
	len = get_word_length(str, separator, *index);
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (str[*index] && str[*index] != separator)
		word[i++] = str[(*index)++];
	word[i] = '\0';
	return (word);
}

static int	count_words(const char *str, char separator)
{
	int	count;
	int	i;
	int	in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (str[i])
	{
		if (str[i] != separator && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (str[i] == separator)
			in_word = 0;
		i++;
	}
	return (count);
}

static char	*create_empty_string(void)
{
	char	*empty;

	empty = malloc(sizeof(char));
	if (!empty)
		return (NULL);
	empty[0] = '\0';
	return (empty);
}

char	**split_input(char *str, char separator)
{
	char	**result;
	int		word_count;
	int		index;
	int		i;

	word_count = count_words(str, separator);
	if (!word_count)
		return (NULL);
	result = malloc(sizeof(char *) * (word_count + 2));
	if (!result)
		return (NULL);
	index = 0;
	i = 0;
	result[i++] = create_empty_string();
	while (--word_count >= 0 && result[0])
	{
		result[i] = extract_word(str, separator, &index);
		if (!result[i++])
		{
			deallocate_string_array(result);
			return (NULL);
		}
	}
	result[i] = NULL;
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milan-godawatta <milan-godawatta@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:27:09 by milan-godaw       #+#    #+#             */
/*   Updated: 2024/12/04 18:16:50 by milan-godaw      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static int	count_words(char *str, char separator)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str == separator)
			str++;
		if (*str)
		{
			count++;
			while (*str && *str != separator)
				str++;
		}
	}
	return (count);
}

static char	*extract_word(char *str, char separator)
{
	int		len;
	char	*word;

	len = 0;
	while (str[len] && str[len] != separator)
		len++;
	word = (char *)malloc(len + 1);
	if (!word)
		return (NULL);
	len = 0;
	while (str[len] && str[len] != separator)
	{
		word[len] = str[len];
		len++;
	}
	word[len] = '\0';
	return (word);
}

static char	**free_words_array(char **array, int i)
{
	while (i > 0)
		free(array[--i]);
	free(array);
	return (NULL);
}

static char	**fill_words_array(char **array, char *str, char separator,
		int word_count)
{
	int	i;

	i = 0;
	while (word_count--)
	{
		while (*str == separator)
			str++;
		if (*str)
		{
			array[i] = extract_word(str, separator);
			if (!array[i])
				return (free_words_array(array, i));
			i++;
			while (*str && *str != separator)
				str++;
		}
	}
	array[i] = NULL;
	return (array);
}

char	**custom_split(char *str, char separator)
{
	int		word_count;
	char	**words_array;

	word_count = count_words(str, separator);
	words_array = (char **)malloc(sizeof(char *) * (word_count + 2));
	if (!words_array)
		return (NULL);
	return (fill_words_array(words_array, str, separator, word_count));
}

/*
char		**custom_split(char *str, char separator);

int	main(void)
{
	char	input[] = "  hello   world   42  ";
	char	separator;
	char	**result;
	int		i;

	separator = ' ';
	result = custom_split(input, separator);
	i = 0;
	if (!result)
	{
		printf("Error: Memory allocation failed.\n");
		return (1);
	}
	printf("Split result:\n");
	while (result[i])
	{
		printf("Word %d: %s\n", i + 1, result[i]);
		free(result[i]);
		i++;
	}
	free(result);
	return (0);
}
*/
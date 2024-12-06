/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:42:12 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/06 12:07:37 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include <stdlib.h>

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

static int	find_next_word(const char *str, char separator, int *current_index,
		int *length)
{
	int	start;

	start = *current_index;
	while (str[start] == separator)
		start++;
	*current_index = start;
	*length = 0;
	while (str[*current_index] != separator && str[*current_index] != '\0')
	{
		(*length)++;
		(*current_index)++;
	}
	return (start);
}

static char	*get_next_word(const char *str, char separator, int *current_index)
{
	int		length;
	int		start;
	char	*word;
	int		i;

	length = 0;
	start = find_next_word(str, separator, current_index, &length);
	word = malloc(length + 1);
	i = 0;
	if (!word)
		return (NULL);
	while (i < length)
	{
		word[i] = str[start + i];
		i++;
	}
	word[length] = '\0';
	return (word);
}

static int	complete_array(char **words, const char *str, char separator,
		int word_count)
{
	int	current_index;
	int	i;

	current_index = 0;
	i = 0;
	words[i] = malloc(1);
	if (!words[i])
		return (0);
	words[i++][0] = '\0';
	while (i <= word_count)
	{
		words[i] = get_next_word(str, separator, &current_index);
		if (!words[i])
		{
			while (--i >= 0)
				free(words[i]);
			return (0);
		}
		i++;
	}
	words[i] = NULL;
	return (1);
}

char	**split(char *str, char separator)
{
	int		word_count;
	char	**words_array;

	word_count = count_words(str, separator);
	words_array = (char **)malloc(sizeof(char *) * (word_count + 2));
	if (!words_array)
		return (NULL);
	if (!complete_array(words_array, str, separator, word_count))
	{
		free(words_array);
		return (NULL);
	}
	return (words_array);
}
/*
int main(int argc, char **argv)
{
    if (argc == 2)
    {
        char **words_array = split(argv[1], ' ');
        printf("Input numbers as a single string\n");
        for (int i = 0; words_array[i]; i++) {
            printf("%s\n", words_array[i]);
            free(words_array[i]);
        }
        free(words_array);
        return 0;
    }
    else if (argc > 2)
    {
        for (int i = 1; i < argc; i++) {
            printf("[%d]: %s\n",i - 1, argv[i]);
        }
        return 0;
    }
    else
        printf("Error\n");
}
*/
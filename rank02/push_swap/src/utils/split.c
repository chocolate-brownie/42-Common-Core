/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:42:12 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/06 11:44:11 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

#include <stdlib.h>

static int count_words(const char *str, const char separator)
{
    int count = 0;
    int inside_word = 0;

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
    return count;
}

static int find_next_word(const char *str, char separator, int *current_index, int *length)
{
    int start = *current_index;

    while (str[start] == separator)
        start++;
    *current_index = start;

    *length = 0;
    while (str[*current_index] != separator && str[*current_index] != '\0')
    {
        (*length)++;
        (*current_index)++;
    }

    return start;
}

static char *get_next_word(const char *str, char separator, int *current_index)
{
    int length = 0;
    int start = find_next_word(str, separator, current_index, &length);
    char *word = malloc(length + 1);
    int i = 0;

    if (!word)
        return NULL;

    while (i < length)
    {
        word[i] = str[start + i];
        i++;
    }
    word[length] = '\0';

    return word;
}

static int complete_array(char **words, const char *str, char separator, int word_count)
{
    int current_index = 0;
    int i = 0;

    words[i] = malloc(1);
    if (!words[i])
        return 0;
    words[i++][0] = '\0';

    while (i <= word_count)
    {
        words[i] = get_next_word(str, separator, &current_index);
        if (!words[i])
        {
            while (--i >= 0)
                free(words[i]);
            return 0;
        }
        i++;
    }
    words[i] = NULL;
    return 1;
}


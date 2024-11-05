/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:08:53 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/04 20:35:00 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int ft_isspace(char c)
{
    return (c == ' ' || (c >= 9 && c <= 13));
}

int count_words(char *str)
{
    int i = 0;
    int word_count = 0;

    while (str[i])
    {
        while (str[i] && ft_isspace(str[i]))
            i++;

        if (str[i])
            word_count++;

        while (str[i] && !ft_isspace(str[i]))
            i++;
    }
    return word_count;
}

char *ft_strncpy(char *dest, char *src, int n)
{
    int i = 0;
    while (i < n && src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

char *copy_word(char *str, int j, int len)
{
    char *word = (char *)malloc(sizeof(char) * (len + 1));
    if (!word)
        return NULL;

    ft_strncpy(word, &str[j], len);
    return word;
}

char **ft_split(char *str)
{
    int i = 0;
    int j = 0;
    int k = 0;

    // count the words
    int word_count = count_words(str);

    char **out = (char **)malloc(sizeof(char *) * (word_count + 1));
    if (!out)
        return NULL;

    while (str[i])
    {
        // skip whitespaces
        while (str[i] && ft_isspace(str[i]))
            i++;

        // start of the word
        j = i;

        // move to the end of the word
        while (str[i] && !ft_isspace(str[i]))
            i++;

        if (i > j)
        {
            out[k] = copy_word(str, j, i - j);
            if (!out[k])
                return NULL;
            k++;
        }
    }
    out[k] = NULL;
    return out;
}

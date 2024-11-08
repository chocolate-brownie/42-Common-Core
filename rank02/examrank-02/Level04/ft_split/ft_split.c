/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:39:21 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/08 11:28:57 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int ft_isspace(char c)
{
    return (c == ' ' || (c >= 9 && c < 13));
}

int count_words(char *str)
{
    int word_count = 0;
    int in_word = 0;

    int i = 0;
    while (str[i])
    {
        if (ft_isspace(str[i]))
            in_word = 0;
        else if (!in_word)
        {
            in_word = 1;
            word_count++;
        }
        i++;
    }

    return word_count;
}

char *copy_word(char *str_start, int len)
{
    char *word = (char *)malloc((len + 1) * sizeof(char));
    if (!word)
        return NULL;

    int i = 0;
    while (i < len)
    {
        word[i] = str_start[i];
        i++;
    }
    word[len] = '\0';
    return word;
}

char **ft_split(char *str)
{
    int index = 0;
    int words = count_words(str);
    char **result = (char **)malloc(sizeof(char *) * (words + 1));
    if (!result)
        return NULL;

    int i = 0;
    while (str[i])
    {
        if (!ft_isspace(str[i]))
        {
            char *word_start = &str[i];
            int length = 0;

            while (str[i] && !ft_isspace(str[i]))
            {
                length++;
                i++;
            }

            result[index] = copy_word(word_start, length);
            if (!result[index])
                return NULL;
            index++;
        }
        else
            i++;
    }
    result[index] = NULL;
    return result;
}

int main(void)
{
    char *test_string = " Hello   world!\nHow  are you? ";
    char **words = ft_split(test_string);
    int i = 0;

    if (words)
    {
        while (words[i])
        {
            printf("Word %d: %s\n", i + 1, words[i]);
            free(words[i]);
            i++;
        }
        free(words);
    }
    else
        printf("ft_split returned NULL.\n");
    return 0;
}

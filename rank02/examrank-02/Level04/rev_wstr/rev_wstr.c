/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:31:27 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/08 12:11:32 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int ft_isspace(char c)
{
    return (c == ' ' || (c >= 9 && c < 13));
}

int count_words(char *str)
{
    int in_word = 0;
    int i = 0;
    int count = 0;

    while (str[i])
    {
        if (ft_isspace(str[i]))
            in_word = 0;
        else if (!in_word)
        {
            in_word = 1;
            count++;
        }
        i++;
    }
    return count;
}

char *copy_words(char *wrd_start, int len)
{
    char *str = (char *)malloc((len + 1) * sizeof(char));
    int i = 0;
    while (i < len)
    {
        str[i] = wrd_start[i];
        i++;
    }
    str[len] = '\0';
    return str;
}

char **ft_split(char *str)
{
    int word_count = count_words(str);
    char **result = (char **)malloc(sizeof(char *) * (word_count + 1));

    int i = 0;
    int len = 0;
    int index = 0;
    while (str[i])
    {
        if (!ft_isspace(str[i]))
        {
            char *start_word = &str[i];
            len = 0;
            while (str[i] && !ft_isspace(str[i]))
            {
                i++;
                len++;
            }

            result[index] = copy_words(start_word, len);
            if (!result[index])
            {
                while (index > 0)
                    free(result[--index]);
                free(result);
                return NULL;
            }
            index++;
        }
        else
            i++;
    }
    result[index] = NULL;
    return result;
}

void ft_putstr(char *str)
{
    int i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        write(1, "\n", 1);
        return 0;
    }
    else
    {
        char *s1 = argv[1];
        char **words = ft_split(s1);
        int word_count = 0;

        while (words[word_count])
            word_count++;

        int i = word_count - 1;
        while (i >= 0)
        {
            ft_putstr(words[i]);
            if (i > 0)
                ft_putstr(" ");
            free(words[i]);
            i--;
        }
        free(words);
    }
    return 0;
}
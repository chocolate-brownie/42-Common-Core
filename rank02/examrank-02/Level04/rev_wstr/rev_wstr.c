/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:35:25 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/04 20:58:21 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void ft_putstr(char *str)
{
    int i = 0;
    while (str[i])
        write(1, &str[i++], 1);
}

int ft_isspace(char c)
{
    return (c == ' ' || (c <= 9 && c >= 13));
}

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}

int count_words(char *str)
{
    int count = 0, in_word = 0;

    int i = 0;
    while (str[i])
    {
        if (!ft_isspace(str[i]))
        {
            if (!in_word)
            {
                count++;
                in_word = 1;
            }
        }
        else
            in_word = 0;
        i++;
    }
    return count;
}

char *ft_strndup(const char *src, int n)
{
    int len = 0;
    while (src[len] != '\0' && len < n)
        len++;

    char *dup = (char *)malloc(len + 1);
    if (!dup)
        return NULL;

    for (int i = 0; i < len; i++)
        dup[i] = src[i];
    dup[len] = '\0';
    return dup;
}

char **split_words(char *str, int *word_count)
{
    *word_count = count_words(str);

    char **words = malloc(sizeof(char *) * (*word_count));
    if (!words)
        return NULL;

    int i = 0;
    while (str[i])
    {
        while (ft_isspace(str[i]))
            i++;

        int strt_wrd = i;
        while (!ft_isspace(str[i]))
            i++;

        int k = 0;
        while (i > strt_wrd)
        {
            words[k] = ft_strndup(&str[strt_wrd], i - strt_wrd);
            if (!words[k])
                return NULL;
            k++;
        }
    }
    return words;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        ft_putstr("\n");
        return 0;
    }

    int word_count;
    char **words = split_words(argv[1], &word_count);
    if (!words)
        return 1;

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
    ft_putstr("\n");
    return 0;
}
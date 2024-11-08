/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:11:44 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/08 14:11:07 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int ft_isspace(char c)
{
    return (c == ' ' || (c >= 9 && c <= 13));
}

int count_words(char *str)
{
    int word_count = 0;
    int flag = 0;

    int i = 0;
    while (str[i])
    {
        if (ft_isspace(str[i]))
            flag = 0;
        else if (!flag)
        {
            flag = 1;
            word_count++;
        }
        i++;
    }
    return word_count;
}

char *copy_word(char *wrd_strt, int wrd_length)
{
    char *str = (char *)malloc(sizeof(char) * (wrd_length + 1));
    if (!str)
        return NULL;

    int i = 0;
    while (i < wrd_length)
    {
        str[i] = wrd_strt[i];
        i++;
    }
    str[wrd_length] = '\0';
    return str;
}

char **ft_split(char *str)
{
    int word_count = count_words(str);
    char **result = (char **)malloc(sizeof(char *) * (word_count + 1));
    if (!result)
        return NULL;

    int i = 0;
    int k = 0;
    while (str[i])
    {
        if (!ft_isspace(str[i]))
        {
            char *wrd_start = &str[i];
            int wrd_lenth = 0;

            while (str[i] && !ft_isspace(str[i]))
            {
                wrd_lenth++;
                i++;
            }

            result[k] = copy_word(wrd_start, wrd_lenth);
            if (!result[k])
            {
                while (k > 0)
                    free(result[--k]);
                free(result);
                return NULL;
            }
            k++;
        }
        else
            i++;
    }
    result[k] = NULL;
    return result;
}

void ft_putstr(char *str)
{
    int i = 0;
    while (str[i])
        write(1, &str[i++], 1);
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        write(1, "\n", 1);
        return 0;
    }
    else
    {
        char *str = argv[1];
        char **words = ft_split(str);
        if (!words)
        {
            write(1, "\n", 1);
            return 0;
        }

        int count = 0;
        while (words[count])
            count++;

        if (count == 0)
        {
            write(1, "\n", 1);
            return 0;
        }

        int i = 1;
        while (i < count)
        {
            ft_putstr(words[i]);
            write(1, " ", 1);
            i++;
        }

        ft_putstr(words[0]);
        write(1, "\n", 1);

        i = 0;
        while (i < count)
        {
            free(words[i]);
            i++;
        }
        free(words);
    }
    return 0;
}
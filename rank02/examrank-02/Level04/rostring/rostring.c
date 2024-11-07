/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:17:49 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/06 17:42:41 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_isspace(char c)
{
    return (c == ' ' || (c >= 9 && c <= 13));
}

void skip_whitespaces(char *str, int *i)
{
    while (ft_isspace(str[*i]))
        (*i)++;
}

int find_end(char *str, int i)
{
    while (str[i] && !ft_isspace(str[i]))
        i++;
    return (i);
}

void write_remaining_words(char *str, int *i)
{
    while (str[*i])
    {
        if (ft_isspace(str[*i]))
        {
            skip_whitespaces(str, i);
            if (str[*i])
                write(1, " ", 1);
        }
        else
        {
            write(1, &str[*i], 1);
            (*i)++;
        }
    }
}

void write_first_word(char *str, int start, int end)
{
    int i;

    i = start;
    while (i < end)
    {
        write(1, &str[i], 1);
        i++;
    }
}

int main(int argc, char *argv[])
{
    char *str;
    int i;
    int first_word_start;
    int first_word_end;

    if (argc > 1)
    {
        str = argv[1];
        i = 0;
        skip_whitespaces(str, &i);
        first_word_start = i;
        first_word_end = find_end(str, i);
        i = first_word_end;
        skip_whitespaces(str, &i);
        if (str[i])
        {
            write_remaining_words(str, &i);
            write(1, " ", 1);
        }
        write_first_word(str, first_word_start, first_word_end);
    }
    write(1, "\n", 1);
    return (0);
}

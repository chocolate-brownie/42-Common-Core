/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:07:23 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/13 20:12:06 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_isspace(char c)
{
    return (c == ' ' || (c >= 9 && c <= 13));
}

void write_word(char *start, char *end)
{
    while (start < end)
    {
        write(1, start, 1);
        start++;
    }
}

void epur_str(char *str, int i)
{
    /* if there's a char after skipping spaces proceed to the next
    operations to print the rest of the string with one space */
    int is_space = 0;
    while (str[i])
    {
        if (ft_isspace(str[i]))
            is_space = 1;
        else
        {
            if (is_space)
                write(1, " ", 1);
            is_space = 0;
            write(1, &str[i], 1);
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        char *str = argv[1];
        /* skip the spaces */
        int i = 0;
        while (ft_isspace(str[i]))
            i++;

        /* find the position of first word start and end */
        char *wrd_start = &str[i];
        while (str[i] && !ft_isspace(str[i]))
            i++;
        char *wrd_end = &str[i];
        /* skip spaces again */
        while (ft_isspace(str[i]))
            i++;
        /* only call epur_str if there are more words to print */
        if (str[i] != '\0')
        {
            epur_str(str, i);
            write(1, " ", 1);
        }
        write_word(wrd_start, wrd_end);
    }
    write(1, "\n", 1);
    return 0;
}
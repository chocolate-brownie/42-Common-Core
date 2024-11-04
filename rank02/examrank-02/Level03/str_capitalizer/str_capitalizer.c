/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:50:29 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/04 18:05:07 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_isspace(char c)
{
    return (c == ' ' || (c >= 9 && c <= 13));
}

int ft_isalpha(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int ft_tolower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return c += 32;
    return c;
}

int ft_toupper(char c)
{
    if (c >= 'a' && c <= 'z')
        return c -= 32;
    return c;
}

void str_capitalizer(char *str)
{
    int i = 0;
    int new_word = 1;

    while (str[i])
    {
        if (ft_isalpha(str[i]))
        {
            if (new_word)
            {
                str[i] = ft_toupper(str[i]);
                new_word = 0;
            }
            else
                str[i] = ft_tolower(str[i]);
        }
        else if (ft_isspace(str[i]))
            new_word = 1;
        write(1, &str[i], 1);
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 1)
        write(1, "\n", 1);
    else
    {
        int i = 1;
        while (i < argc)
        {
            str_capitalizer(argv[i]);
            i++;
        }
    }
    return 0;
}
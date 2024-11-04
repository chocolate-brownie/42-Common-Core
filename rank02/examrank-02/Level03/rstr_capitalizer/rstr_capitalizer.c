/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:25:48 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/04 17:50:00 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_isspace(char c)
{
    return (c == ' ' || (c >= 9 && c <= 13));
}

int ft_isalpha(char c)
{
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

char ft_tolower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return c += 32;
    return c;
}

char ft_toupper(char c)
{
    if (c >= 'a' && c <= 'z')
        return c -= 32;
    return c;
}

void rstr_capitalizer(char *str)
{
    int i = 0;
    int last_letter = -1;
    
    while (str[i])
    {
        str[i] = ft_tolower(str[i]);

        if (ft_isalpha(str[i]) && ft_isspace(str[i + 1]) || str[i + 1] == '\0')
            str[i] = ft_toupper(str[i]);
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
        for (int i = 1; i < argc; i++)
        {
            rstr_capitalizer(argv[i]);
            write(1, "\n", 1);
        }
    }
    return 0;
}
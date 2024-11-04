/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:07:20 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/04 15:39:19 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_isspace(char c)
{
    return (c == ' ' || (c >= 9 && c <= 13));
}

void expand_str(char *str)
{
    int i = 0;
    while (ft_isspace(str[i]))
        i++;

    int inside_word = 0;
    
    while (str[i])
    {
        if (!ft_isspace(str[i]))
        {
            if (inside_word)
                write(1, "   ", 3);
            while (str[i] && !ft_isspace(str[i]))
            {
                write(1, &str[i], 1);
                i++;
            }
            inside_word = 1;
        }
        else
            i++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 2 && argv[1][0] != '\0')
        expand_str(argv[1]);
    else
        write(1, "\n", 1);
}
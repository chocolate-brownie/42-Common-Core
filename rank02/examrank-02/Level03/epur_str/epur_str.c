/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:48:36 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/04 15:35:21 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_isspace(char c)
{
    return (c == ' ' || c == '\t');
}

void epur_str(char *str)
{
    int i = 0;
    int inside_word = 0;

    // skip spaces in the beginning if there's any
    while (ft_isspace(str[i]))
        i++;
    
    
    while (str[i])
    {
        if (!ft_isspace(str[i]))
        {
            if (inside_word)
                write(1, " ", 1);
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
    write(1, "\n", 1);
}

int main(int argc, char **argv)
{
    if (argc == 2 && argv[1][0] != '\0')
        epur_str(argv[1]);
    else
        write(1, "\n", 1);
    return 0;
}

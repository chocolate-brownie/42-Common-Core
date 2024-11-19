/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:50:22 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/19 20:53:28 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_isspace(char c)
{
    return (c == ' ' || (c >= 9 && c <= 13));
}

void expand_str(char *str)
{
    int is_space = 0;
    while (ft_isspace(*str))
        str++;

    while (*str)
    {
        if (ft_isspace(*str))
            is_space = 1;
        else
        {
            if (is_space)
                write(1, "   ", 3);
            is_space = 0;
            write(1, str, 1);
        }
        str++;
    }
}

int main(int argc, char *argv[])
{
    if (argc == 2)
        expand_str(argv[1]);
    write(1, "\n", 1);
    return 0;
}
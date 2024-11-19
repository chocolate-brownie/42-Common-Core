/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:12:25 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/19 20:44:28 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_isspace(char c)
{
    return (c == ' ' || (c >= 9 && c <= 13));
}

void epur_str(char *str)
{
    int i = 0;
    int is_space = 0;

    while (ft_isspace(str[i]))
        i++;

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

int main(int argc, char *argv[])
{
    if (argc == 2)
        epur_str(argv[1]);
    write(1, "\n", 1);
    return 0;
}
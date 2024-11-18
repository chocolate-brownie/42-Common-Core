/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:49:00 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/18 16:03:10 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int char_position(char c)
{
    if (c >= 'a' && c <= 'z')
        return c - 'a' + 1;
    if (c >= 'A' && c <= 'Z')
        return c - 'A' + 1;
    return 1;
}

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        char *str = argv[1];
        unsigned int i = 0;

        while (str[i])
        {
            int pos = char_position(str[i]);
            while (pos--)
                write(1, &str[i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return 0;
}
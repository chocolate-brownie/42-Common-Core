/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:07:16 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/18 16:57:13 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int char_position(char c)
{
    if (c >= 'a' && c <= 'z')
        c = ((c - 'a' + 13) % 26) + 'a';
    else if (c >= 'A' && c <= 'Z')
        c = ((c - 'A' + 13) % 26) + 'A';
    return c;
}

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        char *str = argv[1];
        int i = 0;

        while (str[i])
        {
            char c = char_position(str[i]);
            write(1, &c, 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return 0;
}
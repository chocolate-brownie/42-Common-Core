/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:57:34 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/18 17:40:48 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        char *str = argv[1];
        int i = 0;

        while (str[i])
        {
            char c = str[i];
            if (c >= 'a' && c <= 'z')
                c = ((c - 'a' + 1) % 26) + 'a';
            else if (c >= 'A' && c <= 'Z')
                c = ((c - 'A' + 1) % 26) + 'A';
            write(1, &c, 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return 0;
}
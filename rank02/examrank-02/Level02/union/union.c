/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:24:05 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/19 19:38:18 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void unionstr(char *s1, char *s2)
{
    unsigned char seen[256] = {0};
    int i = 0;

    while (s1[i])
    {
        if (!seen[(unsigned char)s1[i]])
        {
            write(1, &s1[i], 1);
            seen[(unsigned char)s1[i]] = 1;
        }
        i++;
    }

    i = 0;
    while (s2[i])
    {
        if (!seen[(unsigned char)s2[i]])
        {
            write(1, &s2[i], 1);
            seen[(unsigned char)s2[i]] = 1;
        }
        i++;
    }
}

int main(int argc, char *argv[])
{
    if (argc == 3)
        unionstr(argv[1], argv[2]);
    write(1, "\n", 1);
    return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:43:34 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/18 21:47:02 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void inter(char *s1, char *s2)
{
    unsigned char seen[256] = {0};
    int i = 0;
    int j = 0;
    while (s1[i])
    {
        j = 0;
        while (s2[j])
        {
            if (s1[i] == s2[j])
            {
                if (!seen[(unsigned char)s1[i]])
                {
                    write(1, &s1[i], 1);
                    seen[(unsigned char)s1[i]] = 1;
                }
            }
            j++;
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 3)
        inter(argv[1], argv[2]);
    write(1, "\n", 1);
    return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:35:50 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/04 16:43:18 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void hidenp(char *s1, char *s2)
{
    int i = 0;
    int j = 0;

    while (s1[i])
    {
        while (s2[j] && s2[j] != s1[i])
            j++;
        
        if (s2[j] == '\0')
        {
            write(1, "0\n", 2);
            return ;
        }
        i++;
        j++;
    }
    write(1, "1\n", 1);
}

int main(int argc, char **argv)
{
    if (argc == 3)
        hidenp(argv[1], argv[2]);
    else
        write(1, "\n", 1);
    return 0;
}
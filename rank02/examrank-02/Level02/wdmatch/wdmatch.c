/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:06:49 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/19 19:12:41 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void wdmatch(char *s1, char *s2)
{
    int i = 0;
    int j = 0;

    while (s1[i] && s2[j])
    {
        if (s1[i] == s2[j])
            i++;
        j++;
    }
    if (s1[i] == '\0')
        write(1, s1, i);
}

int main(int argc, char *argv[])
{
    if (argc == 3)
        wdmatch(argv[1], argv[2]);
    write(1, "\n", 1);
    return 0;
}
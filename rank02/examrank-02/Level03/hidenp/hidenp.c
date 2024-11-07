/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:40:16 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/07 15:58:39 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc == 3) {
        char *s1=argv[1];
        char *s2=argv[2];
        int i = 0;
        int k = 0;

        while (s2[k] && s1[i]) {
            if (s2[k] == s1[i])
                i++;
            k++;
        }
        if (s1[i] == '\0')
            write(1, "1\n", 1);
        else
            write(1, "0\n", 1);
    }
    write(1, "\n", 1);
    return 0;
}

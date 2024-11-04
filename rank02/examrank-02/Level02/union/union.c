/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:10:42 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/04 13:21:57 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc == 3)
    {
        char *str1 = argv[1];
        char *str2 = argv[2];

        int shown[256] = {0};
        
        int i = 0;
        while (str1[i])
        {
            if (!shown[(unsigned char)str1[i]])
            {
                write(1, &str1[i], 1);
                shown[(unsigned char)str1[i]] = 1;
            }
            i++;
        }

        i = 0;
        while (str2[i])
        {
            if (!shown[(unsigned char)str2[i]])
            {
                write(1, &str2[i], 1);
                shown[(unsigned char)str2[i]] = 1;
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return 0;
}

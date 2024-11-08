/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:21:06 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/04 11:35:21 by mgodawat         ###   ########.fr       */
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
        int j;
        while (str1[i])
        {
            j = 0;
            int found_in_s2 = 0;
            while (str2[j])
            {
                if (str1[i] == str2[j])
                {
                    found_in_s2 = 1;
                    break;
                }
                j++;
            }

            if (found_in_s2 && !shown[(unsigned char)str1[i]])
            {
                write(1, &str1[i], 1);
                shown[(unsigned char)str1[i]] = 1;
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return 0;
}

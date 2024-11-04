/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:23:02 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/04 13:37:32 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc == 3)
    {
        char *str1 = argv[1];
        char *str2 = argv[2];

        int i = 0;
        int j = 0;

        int all_found = 1;

        while (str1[i])
        {
            while (str2[j] && str2[j] != str1[i])
                j++;
            
            if (str2[j] == '\0')
            {
                all_found = 0;
                break;
            }
            i++;
            j++;
        }

        if (all_found == 1)
        {
            i = 0;
            while (str1[i])
                write(1, &str1[i++], 1);
        }
    }   
    write(1, "\n", 1); 
    return 0;
}

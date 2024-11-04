/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_to_camel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:01:40 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/04 13:09:37 by mgodawat         ###   ########.fr       */
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
            if (str[i] == '_')
            {
                i++;
                str[i] -= 32;
            }
            write(1, &str[i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_to_camel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:39:59 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/19 19:43:03 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void snake_to_camel(char *str)
{
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

int main(int argc, char *argv[])
{
    if (argc == 2)
        snake_to_camel(argv[1]);
    write(1, "\n", 1);
    return 0;
}
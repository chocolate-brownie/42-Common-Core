/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:52:18 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/02 16:19:50 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
    char *str = argv[1];
    char *replace = argv[2];
    char *replace_with = argv[3];
    unsigned int i = 0;

    if (argc == 4 && replace[1] == '\0' && replace_with[1] == '\0')
    {
        while (str[i])
        {
            if (str[i] == replace[0])
                str[i] = replace_with[0];
            write(1, &str[i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:41:04 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/18 17:46:14 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void search_and_replace(char *str, char search, char replace)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] == search)
            str[i] = replace;
        write(1, &str[i], 1);
        i++;
    }
}

int main(int argc, char *argv[])
{
    if (argc == 4 && !argv[2][1] && !argv[3][1])
        search_and_replace(argv[1], argv[2][0], argv[3][0]);
    write(1, "\n", 1);
    return 0;
}
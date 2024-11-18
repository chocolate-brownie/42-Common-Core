/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:54:35 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/18 17:58:42 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void alpha_mirror(char *str)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = 'z' - str[i] + 'a';
        else if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = 'Z' - str[i] + 'A';
        write(1, &str[i], 1);
        i++;
    }
}

int main(int argc, char *argv[])
{
    if (argc == 2)
        alpha_mirror(argv[1]);
    write(1, "\n", 1);
    return 0;
}
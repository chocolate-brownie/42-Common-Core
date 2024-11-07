/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:48:43 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/07 17:00:39 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_isspace(char c) {
    return (c == ' ' || (c >= 9 && c <= 13));
}

void str_capitalizer(char *str) {
    int i = 0;
    if (str[i] >= 'a' && str[i] <= 'z')
        str[i] -= 32;
    while (str[i]) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        if (str[i] >= 'a' && str[i] <= 'z' && ft_isspace(str[i - 1]))
            str[i] -= 32;
        write(1, &str[i++], 1);
    }
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        write(1, "\n", 1);
    } else {
        int i = 1;
        while (i < argc) {
            str_capitalizer(argv[i]);
            write(1, "\n", 1);
            i++;
        }
    }
    return 0;
}

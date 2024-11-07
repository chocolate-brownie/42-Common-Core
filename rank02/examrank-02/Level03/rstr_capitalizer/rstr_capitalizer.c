/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:32:32 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/07 16:47:24 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_isspace(char c) {
    return (c == ' ' || (c >= 9 && c <= 13));
}

void rstr_capitalizer(char *str) {
    int i = 0;
    while (str[i]) {
    // make everything lowercase first
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        if ((str[i] >= 'a' && str[i] <= 'z') && ft_isspace(str[i + 1]) || str[i + 1] == '\0') 
            str[i] -= 32;
        write(1, &str[i], 1);
        i++;
    }
}

int main(int argc, char **argv) {

    if (argc == 1) {
        write(1, "\n", 1);
        return 0;
    }
    else {
        int i = 1;
        while (i < argc) {
            rstr_capitalizer(argv[i]);
            write(1, "\n", 1);
            i++;
        }

    }


    return 0;
}

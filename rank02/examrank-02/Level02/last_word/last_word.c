/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 21:48:04 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/18 22:14:08 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_isspace(char c)
{
    return (c == ' ' || (c >= 9 && c <= 13));
}

void last_word(char *str)
{
    int end = 0;
    int last_letter = 0;
    while (str[end])
        end++;
    end--; // take the index away from the null terminator

    while (ft_isspace(str[end]) && end >= 0)
        end--;
    last_letter = end;
    while (!ft_isspace(str[end]) && end >= 0)
        end--;
    end++;                     // take the index to the first letter of the last word
    while (end <= last_letter) // until reach the last letter print
        write(1, &str[end++], 1);
}

int main(int argc, char *argv[])
{
    if (argc == 2)
        last_word(argv[1]);
    write(1, "\n", 1);
    return 0;
}

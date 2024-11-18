/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:31:52 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/18 15:35:17 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_isspace(char c)
{
    return (c == ' ' || (c >= 9 && c <= 13));
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        char *str = argv[1];
        int i = 0;
        while (ft_isspace(str[i]))
            i++;
        while (str[i] && !ft_isspace(str[i]))
            write(1, &str[i++], 1);
    }
    write(1, "\n", 1);
    return 0;
}
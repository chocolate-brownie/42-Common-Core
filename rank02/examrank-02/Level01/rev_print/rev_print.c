/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:03:48 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/18 16:06:49 by mgodawat         ###   ########.fr       */
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
            i++;
        while (i--)
            write(1, &str[i], 1);
    }
    write(1, "\n", 1);
    return 0;
}

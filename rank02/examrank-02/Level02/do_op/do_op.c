/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:06:17 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/18 18:37:40 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc == 4 && !argv[2][1])
    {
        if (argv[2][0] == '+')
            printf("%d", atoi(argv[1]) + atoi(argv[3]));
        if (argv[2][0] == '-')
            printf("%d", atoi(argv[1]) - atoi(argv[3]));
        if (argv[2][0] == '*')
            printf("%d", atoi(argv[1]) * atoi(argv[3]));
        if (argv[2][0] == '/')
            printf("%d", atoi(argv[1]) / atoi(argv[3]));
        if (argv[2][0] == '%')
            printf("%d", atoi(argv[1]) % atoi(argv[3]));
    }
    printf("\n");
    return 0;
}
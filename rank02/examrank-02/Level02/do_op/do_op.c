/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:55:21 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/04 10:02:31 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	
	if (argc == 4) {
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

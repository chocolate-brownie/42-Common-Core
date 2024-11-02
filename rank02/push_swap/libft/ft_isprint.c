/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:54:58 by mgodawat          #+#    #+#             */
/*   Updated: 2024/06/02 18:50:57 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1 * 16384);
	return (0);
}

/* #include <ctype.h>
#include <stdio.h>

int	main(void)
{
	int	errors;
	int	original;
	int	custom;

	for (int i = 10; i < 127; i++)
	{
		original = isprint(i);
		custom = ft_isprint(i);
		printf("Char: %c, isprint: %d, ft_isprint: %d", i, original, custom);
		if (original != custom)
		{
			printf("------FAIL\n");
			errors++;
		}
		else
			printf("------PASS\n");
	}
} */

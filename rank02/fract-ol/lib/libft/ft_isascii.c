/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:09:30 by mgodawat          #+#    #+#             */
/*   Updated: 2024/06/02 17:53:39 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/* #include <ctype.h>
#include <stdio.h>

int	main(void)
{
	int errors;
	int original;
	int custom;

	errors = 0;
	for (int i = 0; i < 256; i++)
	{
		original = isascii(i);
		custom = ft_isascii(i);
		printf("Char: %c, isascii: %d, ft_isascii: %d", i, original, custom);
		if (original != custom)
		{
			printf(" -- FAIL\n");
			errors++;
		}
		else
		{
			printf(" -- OK\n");
		}
	}
} */

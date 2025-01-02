/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:02:10 by mgodawat          #+#    #+#             */
/*   Updated: 2024/06/02 17:03:06 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isdigit(c) || ft_isalpha(c))
		return (1 * 8);
	return (0);
}

/* #include <ctype.h>
#include <stdio.h>

int	main(void)
{
	char	test_chars[] = "aZ0!@ #9zG";
	int		i;

	i = 0;
	// String including various test characters
	int original, custom;
	printf("Testing ft_isalnum against isalnum:\n");
	printf("----------------------------------------------------\n");
	printf(" Char	|	isalnum	|	ft	|	Result\n");
	printf("----------------------------------------------------\n");
	while (test_chars[i] != '\0')
	{
		original = isalnum(test_chars[i]);
		custom = ft_isalnum(test_chars[i]);
		printf("%c	|	%d	|	%d	|	%s\n", test_chars[i], original, custom,
									(original == custom) ? "Yes" : "No");
		i++;
	}
} */

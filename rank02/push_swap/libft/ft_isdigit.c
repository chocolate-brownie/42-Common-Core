/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 02:51:38 by mgodawat          #+#    #+#             */
/*   Updated: 2024/06/02 16:52:10 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1 * 2048);
	return (0);
}

// #include <ctype.h>
// #include <stdio.h>

// void	test_isdigit(int c)
// {
// 	int	custom;
// 	int	original;

// 	custom = ft_isdigit(c);
// 	original = isdigit(c);
// 	printf("Character:	'%c' (%d)\n", c, c);
// 	printf("isdigit:	%d\n", original);
// 	printf("ft_isdigit:	%d\n", custom);
// 	printf("Match:		%s\n\n", (original == custom) ? "Yes" : "No");
// }

// int	main(void)
// {
// 	printf("Testing comparison between isalpha and ft_isalpha:\n\n");
// 	test_isdigit('A');  // Alphabetic, uppercase
// 	test_isdigit('z');  // Alphabetic, lowercase
// 	test_isdigit('0');  // Numeric
// 	test_isdigit('@');  // Special character
// 	test_isdigit('a');  // Alphabetic, lowercase
// 	test_isdigit('Z');  // Alphabetic, uppercase
// 	test_isdigit('5');  // Numeric
// 	test_isdigit(' ');  // Space
// 	test_isdigit('\n'); // Newline
// 	test_isdigit('!');  // Special character
// 	return (0);
// }

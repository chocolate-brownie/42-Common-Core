/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncasecmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:25:02 by mgodawat          #+#    #+#             */
/*   Updated: 2025/01/07 09:51:55 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncasecmp(const char *s1, const char *s2, size_t n)
{
	char	c1;
	char	c2;

	if (n == 0)
		return (0);
	while (n-- > 0)
	{
		c1 = ft_tolower((unsigned char)*s1);
		c2 = ft_tolower((unsigned char)*s2);
		if (c1 != c2 || !c1 || !c2)
			return (c1 - c2);
		s1++;
		s2++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasecmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 03:17:09 by mgodawat          #+#    #+#             */
/*   Updated: 2025/01/07 03:25:26 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcasecmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while (s1[i] && s2[i])
	{
		if (ft_tolower(s1[i]) != ft_tolower(s2[i]))
			return ((unsigned char)ft_tolower(s1[i])
				- (unsigned char)ft_tolower(s2[i]));
		i++;
	}
	if (s1[i] || s2[i])
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:26:33 by mgodawat          #+#    #+#             */
/*   Updated: 2024/06/11 18:45:19 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	unsigned int	strlen;
	char			*result;

	index = 0;
	strlen = ft_strlen(s);
	result = malloc((strlen + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	while (index < strlen)
	{
		result[index] = (*f)(index, s[index]);
		index++;
	}
	result[index] = '\0';
	return (result);
}

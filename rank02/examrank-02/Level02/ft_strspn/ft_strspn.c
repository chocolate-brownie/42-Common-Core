/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:56:56 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/02 18:01:04 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	ft_strspn(const char *s, const char *accept)
{
	int i = 0;
	int k;

	while (s[i])
	{
		k = 0;
		while (accept[k])
		{
			if (s[i] == accept[k])
				break;
			k++;
		}
		if (accept[k] == '\0')
			return i;
		i++;
	}
	return i;
}

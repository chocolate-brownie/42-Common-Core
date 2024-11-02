/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:43:31 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/02 17:46:36 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *strpbrk(const char *s, const char *accept)
{
	int i = 0;
	int j;
	while (s[i])
	{
		j = 0;
		while (accept[j])
		{
			if (s[i] == accept[j])
				return (char *)&s[i];
			j++;
		}
		i++;
	}
	return NULL;
}


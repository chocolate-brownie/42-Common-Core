/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:47:54 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/02 17:52:21 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return i;
}

char    *ft_strrev(char *str)
{
	int start = 0;
	int end = ft_strlen(str);
	if (!str)
		return NULL;
	end--;
	while (start < end)
	{
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
	return str;
}

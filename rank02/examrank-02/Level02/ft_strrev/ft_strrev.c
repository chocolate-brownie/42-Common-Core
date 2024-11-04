/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:06:40 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/04 11:10:16 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *ft_strrev(char *str)
{
	int start = 0;
	int end = 0;

	while (str[end])
		end++;
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

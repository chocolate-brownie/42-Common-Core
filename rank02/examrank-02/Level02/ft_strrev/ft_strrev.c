/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:40:13 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/18 20:42:04 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_strrev(char *str)
{
    int start = 0;
    int end = 0;

    while (str[end])
        end++;
    end--;

    while (start <= end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
    return str;
}
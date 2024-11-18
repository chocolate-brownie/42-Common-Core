/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 22:18:41 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/18 22:25:02 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int max(int *tab, unsigned int len)
{
    int i = 0;
    int max = tab[0];
    if (len == 0)
        return 0;
    while (i < len)
    {
        if (tab[i] > max)
            max = tab[i];
        i++;
    }
    return max;
}
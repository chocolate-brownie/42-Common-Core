/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:25:54 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/08 14:30:46 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void sort_int_tab(int *tab, unsigned int size)
{
    unsigned int i = 0;

    while (i < (size - 1))
    {
        if (tab[i] > tab[i + 1])
        {
            int temp = tab[i];
            tab[i] = tab[i + 1];
            tab[i + 1] = temp;

            i = 0;
        }
        else
            i++;
    }
}

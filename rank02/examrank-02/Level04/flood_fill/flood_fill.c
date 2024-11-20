/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:53:05 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/20 18:03:33 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flood_fill.h"
#include <stdio.h>
#include <stdlib.h>

void fill(char **tab, t_point size, int row, int col, char target)
{
    if (row < 0 || col < 0 || row >= size.y || col >= size.x)
        return;
    if (tab[row][col] == 'F' || tab[row][col] != target)
        return;
    tab[row][col] = 'F';
    fill(tab, size, row - 1, col, target);
    fill(tab, size, row + 1, col, target);
    fill(tab, size, row, col - 1, target);
    fill(tab, size, row, col + 1, target);
}

void flood_fill(char **tab, t_point size, t_point begin)
{
    unsigned char target = tab[begin.y][begin.x];
    fill(tab, size, begin.y, begin.x, target);
}

char **make_area(char **zone, t_point size)
{
    char **new;

    new = malloc(sizeof(char *) * size.y);
    for (int i = 0; i < size.y; ++i)
    {
        new[i] = malloc(size.x + 1);
        for (int j = 0; j < size.x; ++j)
            new[i][j] = zone[i][j];
        new[i][size.x] = '\0';
    }

    return new;
}

int main(void)
{
    t_point size = {8, 5};
    char *zone[] = {
        "11111111",
        "10001001",
        "10010001",
        "10110001",
        "11100001",
    };

    char **area = make_area(zone, size);
    for (int i = 0; i < size.y; ++i)
        printf("%s\n", area[i]);
    printf("\n");

    t_point begin = {7, 4};
    flood_fill(area, size, begin);
    for (int i = 0; i < size.y; ++i)
        printf("%s\n", area[i]);
    return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:10:22 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/04 19:29:19 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

typedef struct s_point
{
    int x;
    int y;
} t_point;

void recursive_fill(char **tab, t_point size, int x, int y, char target_char)
{
    if (x < 0 || x >= size.x || y < 0 || y >= size.y)
        return;
    if (tab[y][x] != target_char)
        return;

    tab[y][x] = 'F';

    recursive_fill(tab, size, x + 1, y, target_char);
    recursive_fill(tab, size, x - 1, y, target_char);
    recursive_fill(tab, size, x, y + 1, target_char);
    recursive_fill(tab, size, x, y - 1, target_char);
}

void flood_fill(char **tab, t_point size, t_point begin)
{
    char target_char = tab[begin.y][begin.x];
    if (target_char != 'F')
        recursive_fill(tab, size, begin.x, begin.y, target_char);
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
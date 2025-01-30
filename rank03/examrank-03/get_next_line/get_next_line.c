/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:49:31 by mgodawat          #+#    #+#             */
/*   Updated: 2025/01/30 14:49:48 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

char    *ft_strdup(char *str)
{
    int     i;
    char    *dest;

    i = 0;
    while (str[i])
        i++;
    dest = (char *)malloc(sizeof(char) * (i + 1));
    i = 0;
    while (str[i])
    {
        dest[i] = str[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char    *get_next_line(int fd)
{
    int         i;
    char        line[7000];
    static char buffer[BUFFER_SIZE];
    static int  buffer_read;
    static int  buffer_pos;

    i = 0;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    while (1)
    {
        if (buffer_pos >= buffer_read)
        {
            buffer_read = read(fd, buffer, BUFFER_SIZE);
            buffer_pos = 0;
            if (buffer_read <= 0)
                break ;
        }
        line[i++] = buffer[buffer_pos++];
        if (buffer[buffer_pos] == '\n')
            break;
    }
    line[i] = '\0';
    if (i == 0)
        return (NULL);
    return (ft_strdup(line));
}

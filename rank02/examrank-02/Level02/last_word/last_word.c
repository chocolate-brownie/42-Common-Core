/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:38:13 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/04 11:52:58 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int isspace(int c)
{
    return (c == ' ' || (c >= 9 && c <= 13));
}

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        char *str = argv[1];
        int i = 0;

        // find the end of the string
        while (str[i])
            i++;
        // move back to the last char from the null        
        i--;
        // skip spaces from the end
        while (i >= 0 && isspace(str[i]))
            i--;
        // mark the position of the last char of the last word
        int end = i;
        // i-- until you find a space
        while (i >= 0 && !isspace(str[i]))
            i--;
        // take the index from the space to a the beginning of the word
        int start = i + 1;
        // now write
        while (start <= end)
            write(1, &str[start++], 1);    
    }
    write(1, "\n", 1);
    return 0;
}

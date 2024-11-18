/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:04:33 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/18 19:09:33 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t ft_strcspn(const char *s, const char *reject)
{
    size_t i = 0;
    size_t j;

    while (s[i])
    {
        j = 0;
        while (reject[j])
        {
            if (s[i] == reject[j])
                return i;
            j++;
        }
        i++;
    }
    return i;
}

#include <stdio.h>
#include <stddef.h>

size_t ft_strcspn(const char *s, const char *reject);

int main(void)
{
    // Test cases
    printf("Test 1: \"%s\", \"%s\" -> %zu\n", "hello, world", "aeiou", ft_strcspn("hello, world", "aeiou")); // Expected: 1
    printf("Test 2: \"%s\", \"%s\" -> %zu\n", "1234567890", "456", ft_strcspn("1234567890", "456"));         // Expected: 3
    printf("Test 3: \"%s\", \"%s\" -> %zu\n", "abcdef", "x", ft_strcspn("abcdef", "x"));                     // Expected: 6
    printf("Test 4: \"%s\", \"%s\" -> %zu\n", "abcdef", "ef", ft_strcspn("abcdef", "ef"));                   // Expected: 4
    printf("Test 5: \"%s\", \"%s\" -> %zu\n", "42 is the answer", " ", ft_strcspn("42 is the answer", " ")); // Expected: 2
    printf("Test 6: \"%s\", \"%s\" -> %zu\n", "", "abc", ft_strcspn("", "abc"));                             // Expected: 0
    printf("Test 7: \"%s\", \"%s\" -> %zu\n", "no match here", "", ft_strcspn("no match here", ""));         // Expected: 12

    return 0;
}

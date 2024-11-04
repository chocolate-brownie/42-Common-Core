/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:45:23 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/04 14:46:41 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void putnbr(int num)
{
    if (num >= 10)
        putnbr(num / 10);
    
    char digit = num % 10 + '0';
    write(1, &digit, 1);
}

int atoi(char *str)
{
    int i = 0;
    int result = 0;
    
    while (str[i] >= '0' && str[i] <= '9') 
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return result;    
}

int isprime(int n)
{
    if (n < 2)
        return 0;
    
    int i = 2;
    while (i <= n / 2)
    {
        if (n % i == 0)
            return 0;
        i++;
    }
    return 1;
}

int main(int argc, char *argv[])
{
    if (argc != 2 || atoi(argv[1]) <= 0)
    {
        write(1, "\n", 1);
        return 0;        
    }
    
    int sum = 0;
    int n = atoi(argv[1]);

    while (n > 1)
    {
        if (isprime(n))
            sum += n;
        n--;
    }
    
    putnbr(sum);
    write(1, "\n", 1);
    return 0;
}

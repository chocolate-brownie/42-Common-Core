/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizz_buzz.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 13:39:34 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/02 13:55:46 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putnbr(int num) {
	if (num >= 10)
		ft_putnbr(num / 10);
	char digit = num % 10 + '0';
	write(1, &digit, 1);
}

int main(void)
{
	int i = 1;
	while (i <= 100) {
		if (i % 15 == 0)	
			write(1, "fizzbuzz", 8);
		else if (i % 3 == 0)
			write(1, "fizz", 4);
		else if (i % 5 == 0)
			write(1, "buzz", 4);
		else
			ft_putnbr(i);
		write(1, "\n", 1);
		i++;
	}
	return 0;
}

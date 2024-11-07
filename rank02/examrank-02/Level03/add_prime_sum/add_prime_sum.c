/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:28:44 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/07 13:50:04 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_isprime(int nbr)
{
	int	i;

	i = 2;
	if (nbr <= 1)
		return (0);
	while (i * i <= nbr)
	{
		if (nbr % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_putnbr(int nbr)
{
	char	digit;

	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	digit = nbr % 10 + '0';
	write(1, &digit, 1);
}

int	ft_atoi(char *str)
{
	char	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	main(int argc, char *argv[])
{
	int	num;
	int	sum;

	if (argc == 2)
	{
		num = ft_atoi(argv[1]);
		sum = 0;
		while (num > 0)
		{
			if (ft_isprime(num))
				sum += num;
			num--;
		}
		ft_putnbr(sum);
	}
	if (argc != 2)
		ft_putnbr(0);
	write(1, "\n", 1);
	return (0);
}

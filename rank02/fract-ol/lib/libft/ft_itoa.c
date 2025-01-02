/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:24:12 by mgodawat          #+#    #+#             */
/*   Updated: 2024/06/11 18:23:17 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_intlen(long nbr)
{
	int	count;

	count = 0;
	if (nbr <= 0)
	{
		count++;
		nbr = -nbr;
	}
	while (nbr != 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

static char	*custom_malloc(int len)
{
	char	*temp;

	temp = malloc((len + 1) * sizeof(char));
	if (temp == NULL)
		return (NULL);
	temp[0] = '\0';
	return (temp);
}

static long	handle_negative(long nbr, char *result)
{
	if (nbr < 0)
	{
		result[0] = '-';
		return (-nbr);
	}
	return (nbr);
}

char	*ft_itoa(int n)
{
	int		n_len;
	char	*result;
	long	nbr;
	int		index;

	nbr = n;
	n_len = ft_intlen(nbr);
	result = custom_malloc(n_len);
	if (result == NULL)
		return (NULL);
	index = n_len;
	nbr = handle_negative(nbr, result);
	result[index--] = '\0';
	if (nbr == 0)
	{
		result[0] = '0';
		return (result);
	}
	while (nbr != 0)
	{
		result[index--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (result);
}

/* int	main(void)

{
	int		number;
	char	*snumber;

	number = 2187316;
	snumber = ft_itoa(number);
	printf("the string: %s\n", snumber);
} */

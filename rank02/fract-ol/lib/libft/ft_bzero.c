/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:24:47 by mgodawat          #+#    #+#             */
/*   Updated: 2024/06/03 17:14:03 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			counter;

	ptr = (unsigned char *)s;
	counter = 0;
	while (counter < n)
	{
		ptr[counter] = 0;
		counter++;
	}
}

/* int	main(void)
{
	char	word[] = "Hello";

	ft_bzero(word, 2);
	printf("%s\n", word);
} */

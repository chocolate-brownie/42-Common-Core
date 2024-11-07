/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:12:01 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/07 15:31:29 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int	size;
	int	*range;
	int	i;

	size = 0;
	if (start <= end)
		size = end - start + 1;
	else if (start >= end)
		size = start - end + 1;
	range = (int *)malloc(size * sizeof(int));
	if (!range)
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (start <= end)
			range[i] = start + i;
		else
			range[i] = start - i;
		i++;
	}
	return (range);
}

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int start, int end);

int	main(void)
{
	int	*range;
	int	size;
	int	start;
	int	end;

	start = 0;
	end = -3;
	size = (start <= end) ? (end - start + 1) : (start - end + 1);
	range = ft_range(start, end);
	if (!range)
		return (1);
	for (int i = 0; i < size; i++)
		printf("%d ", range[i]);
	printf("\n");
	free(range);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 18:01:08 by mgodawat          #+#    #+#             */
/*   Updated: 2024/06/08 18:34:56 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t num_elements, size_t element_size)
{
	size_t	total_size;
	void	*memory;

	total_size = num_elements * element_size;
	memory = malloc(total_size);
	if (memory == NULL)
		return (NULL);
	ft_memset(memory, 0, total_size);
	return (memory);
}

/* FUNCTION ft_calloc(num_elements, size_of_element)
	// Calculate the total size to allocate
	SET total_size TO num_elements * size_of_element

	// Check for multiplication overflow
	IF total_size IS LESS THAN num_elements OR size_of_element IS ZERO
		RETURN NULL
	// Allocate memory
	// Check if memory allocation was successful
	IF memory IS NULL
		RETURN NULL

	// Initialize allocated memory to zero
	SET current_pointer TO memory

	// Return pointer to allocated memory
	RETURN memory
END FUNCTION */

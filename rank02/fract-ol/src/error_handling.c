/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:21:38 by mgodawat          #+#    #+#             */
/*   Updated: 2025/01/02 18:26:46 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/**
 * Checks if input matches a valid fractal name
 * Returns number code for the fractal type
 */
int	is_valid_fractal(char *name)
{
	if (!strcmp(name, FRACTAL_MANDELBROT))
		return (1);
	else if (!strcmp(name, FRACTAL_JULIA))
		return (2);
	else if (!strcmp(name, FRACTAL_BURNING_SHIP))
		return (3);
	else if (!strcmp(name, FRACTAL_MANDELBROT3))
		return (4);
	else if (!strcmp(name, FRACTAL_MANDELBROT4))
		return (5);
	return (0);
}

/**
 * Shows error for wrong program input
 * Lists available fractal options
 */
void	print_usage_error(void)
{
	ft_printf("%s: Invalid Input! Choose one of the following:\n",
		PROGRAM_NAME);
	ft_printf("\t- %s\n\t- %s\n\t- %s\n\t- %s\n\t- %s\n", FRACTAL_MANDELBROT,
		FRACTAL_JULIA, FRACTAL_BURNING_SHIP, FRACTAL_MANDELBROT3,
		FRACTAL_MANDELBROT4);
	exit(1);
}

/**
 * Shows error when graphics system fails
 */
void	print_mlx_error(char *fractal_name)
{
	ft_printf("%s: %s: Failed to init mlx\n", PROGRAM_NAME, fractal_name);
	exit(2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:41:56 by mgodawat          #+#    #+#             */
/*   Updated: 2025/01/04 19:43:09 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/** @details Maps a value from one range to another using linear interpolation
 *
 * @note TLDR, Explain Like I'm 5:
 * Imagine we have a ruler that's 10cm long,
	and another ruler that's 100cm long.
 * If you point at 5cm on the first ruler (halfway),
 * where would that same point be on the 100cm ruler? It'd be at 50cm!
 *
 * This function does exactly that - it takes a point from one range (ruler)
 * and finds where that same point would be in another range (ruler).
 *
 * For Mandelbrot:
 * - We take screen coordinates (like 0 to 800 pixels)
 * - And convert them to Mandelbrot coordinates (-2 to +2)
 * So if you click in the middle of the screen, we can find
 * the exact Mandelbrot point that matches!
 *
 * @param unscaled_num The input number to convert
 * @param old_min The minimum of the original range
 * @param old_max The maximum of the original range
 * @param new_min The minimum of the target range
 * @param new_max The maximum of the target range
 *
 * @return The input number mapped to the new range
 */
double	map(t_fractal *ptr)
{
	double	result;

	result = ((ptr->param.new_max - ptr->param.new_min)
			* (ptr->param.unscaled_num - ptr->param.old_min)
			/ (ptr->param.old_max - ptr->param.old_min) + ptr->param.new_min);
	return (result);
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x_real = z1.x_real + z2.x_real;
	result.y_imaginary = z1.y_imaginary + z2.y_imaginary;
	return (result);
}

/**
 * real_x = (x ^ 2 - y ^ 2)
 * imag_y = 2 * x * y
 */
t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x_real = (z.x_real * z.x_real) - (z.y_imaginary * z.y_imaginary);
	result.y_imaginary = 2 * z.x_real * z.y_imaginary;
	return (result);
}





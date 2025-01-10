/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:56:12 by mgodawat          #+#    #+#             */
/*   Updated: 2025/01/07 12:08:18 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/**
 * @brief z = z² + c calculating the POINT
 * find the square root of the z(complex_real) (z.x * z.x)
 * find the negative imaginary z(complex_imag) and minus it and add the
 * real part of the constant c make sure you hold the complex_real value for the
 * next calculation
 * calculate the imaginary part of z(complex_imag) and add the imaginary
 * part of the constant
 *
 * take the transformed cordinates for the current pixel and check whether the
 * magnititude squared has not escaped > 4
 * if it escaped paint other colors if not paint black
 * havent reached the maximum iteration limit
 * also you have to check whether the point has escaped or not
 * each iteration z.x and z.y should be updated
 *
 * C = (centerx + centery×i) + ((x - WIDTH/2) + (y - HEIGHT/2)×i) × zoom
 *
 */
static double	compute_iteration(t_fractal *vars, double cx, double cy)
{
	double	tmp;

	tmp = vars->complex_real * vars->complex_real - vars->complex_imag
		* vars->complex_imag + cx;
	vars->complex_imag = 2 * vars->complex_real * vars->complex_imag + cy;
	vars->complex_real = tmp;
	return (vars->complex_real * vars->complex_real + vars->complex_imag
		* vars->complex_imag);
}

void	draw_mandelbrot(t_fractal *vars, int x, int y)
{
	int		i;
	double	cx;
	double	cy;

	i = 0;
	vars->complex_real = 0.0;
	vars->complex_imag = 0.0;
	cx = vars->center_x + (x - SIZE_W / 2) * vars->zoom_level;
	cy = vars->center_y + (y - SIZE_H / 2) * vars->zoom_level;
	while (++i < vars->max_iterations && compute_iteration(vars, cx, cy) < 4.0)
		;
	if (i == vars->max_iterations)
		my_mlx_pixel_put(&vars->image, x, y, create_trgb(0, 11, 5, 0));
	else
		my_mlx_pixel_put(&vars->image, x, y, get_pallete(i,
				vars->palette_number));
}

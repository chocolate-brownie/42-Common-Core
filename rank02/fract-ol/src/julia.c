/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 04:14:16 by mgodawat          #+#    #+#             */
/*   Updated: 2025/01/07 12:04:57 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/**
 * @brief samething as mandelbrot but it uses the pixel cordinates as the
 * starting point
 * Julia set: c is fixed, and you test different starting values of z
 */

void	draw_julia(t_fractal *vars, int x, int y)
{
	int		i;
	double	tmp;

	i = 0;
	vars->complex_real = vars->center_x + (x - SIZE_W / 2) * vars->zoom_level;
	vars->complex_imag = vars->center_y + (y - SIZE_H / 2) * vars->zoom_level;
	while (++i < vars->max_iterations)
	{
		tmp = vars->complex_real;
		vars->complex_real = vars->complex_real * vars->complex_real
			- vars->complex_imag * vars->complex_imag + vars->julia_real;
		vars->complex_imag = 2 * vars->complex_imag * tmp + vars->julia_imag;
		if (vars->complex_real * vars->complex_real + vars->complex_imag
			* vars->complex_imag >= 4.0)
			break ;
	}
	if (i == vars->max_iterations)
		my_mlx_pixel_put(&vars->image, x, y, create_trgb(0, 11, 5, 0));
	else
		my_mlx_pixel_put(&vars->image, x, y, get_pallete(i,
				vars->palette_number));
}

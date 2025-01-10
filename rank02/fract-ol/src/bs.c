/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bs.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 04:14:43 by mgodawat          #+#    #+#             */
/*   Updated: 2025/01/07 04:15:20 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static double	compute_burning_ship(t_fractal *fractal, double cx, double cy)
{
	double	tmp;

	tmp = fractal->complex_real * fractal->complex_real - fractal->complex_imag
		* fractal->complex_imag + cx;
	fractal->complex_imag = fabs(2.0 * fractal->complex_real
			* fractal->complex_imag) + cy;
	fractal->complex_real = tmp;
	return (fractal->complex_real * fractal->complex_real
		+ fractal->complex_imag * fractal->complex_imag);
}

void	draw_burning_ship(t_fractal *fractal, int x, int y)
{
	int		i;
	double	cx;
	double	cy;

	i = 0;
	fractal->complex_real = 0.0;
	fractal->complex_imag = 0.0;
	cx = fractal->center_x + (x - SIZE_W / 2) * fractal->zoom_level;
	cy = fractal->center_y + (y - SIZE_H / 2) * fractal->zoom_level;
	while (++i < fractal->max_iterations && compute_burning_ship(fractal, cx,
			cy) < 4.0)
		;
	if (i == fractal->max_iterations)
		my_mlx_pixel_put(&fractal->image, x, y, create_trgb(0, 11, 5, 0));
	else
		my_mlx_pixel_put(&fractal->image, x, y, get_pallete(i,
				fractal->palette_number));
}

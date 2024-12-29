/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 22:34:42 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/29 22:44:51 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

/**
 * @brief The init_view function sets up the mathematical boundaries and
 * parameters needed to calculate the fractal
 * Think of it like setting up a camera:
 *init_mlx = setting up your screen/display
 *init_view = positioning your camera (where you're looking in the
 *mathematical space)
 *You need both before you can start rendering because:
 *You need a place to draw (MLX window and image)
 *You need to know what part of the fractal to draw (view boundaries)
 */

void	init_view(t_fractol *fractol)
{
	if (!fractol)
		clean_exit(NULL, "Failed to initialize the view!", 1);

	if (fractol->params.id == MANDELBROT)
	{
		fractol->math.min_real = -2.0;
		fractol->math.max_real = 1.0;
		fractol->math.min_imag = -1.5;
		fractol->math.max_imag = 1.5;
		fractol->math.max_iter = 100;
	}
	else if (fractol->params.id == JULIA)
	{
		fractol->math.min_real = -2.0;
		fractol->math.max_real = 2.0;
		fractol->math.min_imag = -2.0;
		fractol->math.max_imag = 2.0;
		fractol->math.max_iter = 100;
	}
	else if (fractol->params.id == BURNING_SHIP)
	{
		fractol->math.min_real = -2.0;
		fractol->math.max_real = 1.0;
		fractol->math.min_imag = -2.0;
		fractol->math.max_imag = 1.0;
		fractol->math.max_iter = 100;
	}

	fractol->math.zoom = WIDTH / (fractol->math.max_real
			- fractol->math.min_real);
}
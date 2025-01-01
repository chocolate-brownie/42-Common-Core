/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 22:34:42 by mgodawat          #+#    #+#             */
/*   Updated: 2025/01/01 17:35:24 by milan-god        ###   ########.fr       */
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

static void	init_mandelbrot(t_math *math)
{
	math->min_real = -2.0;
	math->max_real = 1.0;
	math->min_imag = -1.5;
	math->max_imag = 1.5;
	math->max_iter = 100;
}

static void	init_julia(t_math *math)
{
	math->min_real = -2.0;
	math->max_real = 2.0;
	math->min_imag = -2.0;
	math->max_imag = 2.0;
	math->max_iter = 100;
}

static void	init_burning_ship(t_math *math)
{
	math->min_real = -2.0;
	math->max_real = 1.0;
	math->min_imag = -2.0;
	math->max_imag = 1.0;
	math->max_iter = 100;
}

void	init_view(t_fractol *fractol)
{
	if (!fractol)
		clean_exit(NULL, "Failed to initialize the view!", 1);
	if (fractol->params.id == MANDELBROT)
		init_mandelbrot(&fractol->math);
	else if (fractol->params.id == JULIA)
		init_julia(&fractol->math);
	else if (fractol->params.id == BURNING_SHIP)
		init_burning_ship(&fractol->math);
	fractol->math.zoom = WIDTH / (fractol->math.max_real
			- fractol->math.min_real);
}

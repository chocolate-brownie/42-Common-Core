/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:22:05 by mgodawat          #+#    #+#             */
/*   Updated: 2025/01/07 05:00:03 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	btnclose_hook(t_fractal *vars)
{
	destroy(vars);
	return (0);
}

void	my_mlx_pixel_put(t_image_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->pixel_addr + (y * data->line_size + x * (data->bits_per_pixel
				/ 8));
	*(unsigned int *)dst = color;
}

int	destroy(t_fractal *vars)
{
	mlx_destroy_image(vars->mlx_ptr, vars->image.image_ptr);
	mlx_destroy_window(vars->mlx_ptr, vars->window_ptr);
	mlx_destroy_display(vars->mlx_ptr);
	free(vars->mlx_ptr);
	exit(0);
	return (0);
}

int	zoom(int button, int x, int y, t_fractal *vars)
{
	double	fx;
	double	fy;

	fx = vars->center_x + (x - SIZE_W / 2) * vars->zoom_level;
	fy = vars->center_y + (y - SIZE_H / 2) * vars->zoom_level;
	if (button == 4)
	{
		vars->zoom_level /= ZOOM_FACTOR;
		vars->max_iterations += 1.0;
	}
	else if (button == 5)
	{
		vars->zoom_level *= ZOOM_FACTOR;
		if (vars->max_iterations > 2)
			vars->max_iterations -= 1.0;
	}
	vars->center_x = fx - (x - SIZE_W / 2) * vars->zoom_level;
	vars->center_y = fy - (y - SIZE_H / 2) * vars->zoom_level;
	return (0);
}

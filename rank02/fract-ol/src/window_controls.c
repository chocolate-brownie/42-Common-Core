/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_controls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:20:42 by mgodawat          #+#    #+#             */
/*   Updated: 2025/01/02 18:37:14 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/**
 * Puts a colored pixel on the image at position (x,y)
 */
void	set_pixel(t_image *img, int x, int y, int color)
{
	char	*pixel_pos;

	pixel_pos = img->pixel_data + (y * img->line_size + x * (img->bits_per_pixel
				/ 8));
	*(unsigned int *)pixel_pos = color;
}

/**
 * Cleans up memory and exits program
 */
int	cleanup_and_exit(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_ptr, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
	mlx_destroy_display(fractal->mlx_ptr);
	free(fractal->mlx_ptr);
	exit(0);
	return (0);
}

/**
 * Handles keyboard controls for moving and changing colors
 */
int	handle_keypress(int key, t_fractal *fractal)
{
	if (key == 'a' || key == 65361)
		fractal->center_x -= MOVEMENT_STEP * fractal->zoom_level;
	else if (key == 'd' || key == 65363)
		fractal->center_x += MOVEMENT_STEP * fractal->zoom_level;
	else if (key == 'w' || key == 65362)
		fractal->center_y -= MOVEMENT_STEP * fractal->zoom_level;
	else if (key == 's' || key == 65364)
		fractal->center_y += MOVEMENT_STEP * fractal->zoom_level;
	handle_extra_keys(key, fractal);
	return (0);
}

/**
 * Handles extra keyboard controls for iterations and colors
 */
static void	handle_extra_keys(int key, t_fractal *fractal)
{
	if (key == 61 || key == 65451)
		fractal->max_iterations += 2;
	else if (key == 45 || key == 65453)
		fractal->max_iterations -= 2;
	else if (key == 65307)
		cleanup_and_exit(fractal);
	else if (key == 65470)
		fractal->color_palette = 1;
	else if (key == 65471)
		fractal->color_palette = 2;
	else if (key == 65472)
		fractal->color_palette = 3;
}

/**
 * Handles mouse zoom, keeping center at mouse position
 */
int	handle_zoom(int button, int x, int y, t_fractal *fractal)
{
	double	mouse_x;
	double	mouse_y;

	mouse_x = fractal->center_x + (x - WINDOW_WIDTH / 2) * fractal->zoom_level;
	mouse_y = fractal->center_y + (y - WINDOW_HEIGHT / 2) * fractal->zoom_level;
	if (button == 4)
		fractal->zoom_level /= ZOOM_FACTOR;
	else if (button == 5)
		fractal->zoom_level *= ZOOM_FACTOR;
	fractal->center_x = mouse_x - (x - WINDOW_WIDTH / 2) * fractal->zoom_level;
	fractal->center_y = mouse_y - (y - WINDOW_HEIGHT / 2) * fractal->zoom_level;
	return (0);
}

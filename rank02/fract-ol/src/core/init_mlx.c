/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:57:22 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/29 22:36:20 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

/**
 * @brief initiating the mlx
 * init connection, window and image
 * mlx_new_image = "Give me a canvas"
 * mlx_get_data_addr = "Now give me the actual address where I can paint on
 * this canvas"
 * Later, you'll use this address to write pixel colors for your fractal,
 * then use mlx_put_image_to_window to display the complete image.
 * @note think of it like this where we creates window, sets up image buffer
 * prepares the "canvas" where we'll draw
 */
void	init_mlx(t_fractol *fractol)
{
	if (!fractol)
		clean_exit(NULL, "Failed to initialize the program!", 1);
	fractol->connection = mlx_init();
	if (!fractol->connection)
		clean_exit(fractol, "Failed to initialize the mlx!", 1);
	fractol->window = mlx_new_window(fractol->connection, WIDTH, HEIGHT,
			fractol->params.name);
	if (!fractol->window)
		clean_exit(fractol, "Failed to create a window!", 1);
	fractol->image.ptr_img = mlx_new_image(fractol->connection, WIDTH, HEIGHT);
	if (!fractol->image.ptr_img)
		clean_exit(fractol, "Failed to process an image!", 1);
	fractol->image.ptr_pixels = mlx_get_data_addr(fractol->image.ptr_img,
			&fractol->image.bits_per_pixel, &fractol->image.line_length,
			&fractol->image.endian);
}

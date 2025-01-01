/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_buffer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 15:03:34 by mgodawat          #+#    #+#             */
/*   Updated: 2025/01/01 15:03:51 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	swap_buffers(t_fractol *fractol)
{
	void	*temp_img;
	char	*temp_pixels;

	temp_img = fractol->image.ptr_img;
	temp_pixels = fractol->image.ptr_pixels;
	fractol->image.ptr_img = fractol->image.ptr_img_back;
	fractol->image.ptr_pixels = fractol->image.ptr_pixels_back;
	fractol->image.ptr_img_back = temp_img;
	fractol->image.ptr_pixels_back = temp_pixels;
	mlx_put_image_to_window(fractol->connection, fractol->window,
		fractol->image.ptr_img, 0, 0);
}

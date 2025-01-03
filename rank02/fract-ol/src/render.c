/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:06:45 by mgodawat          #+#    #+#             */
/*   Updated: 2025/01/03 20:06:53 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	swap_buffers(t_fractal *fractal)
{
	mlx_put_image_to_window(fractal->conn, fractal->win,
		fractal->img[fractal->curr_img].img_ptr, 0, 0);
	fractal->curr_img = (fractal->curr_img + 1) % 2;
}

static void	put_pixel(t_img *img, int x, int y, int color)
{
	char *pixel;

	pixel = img->pix_ptr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}
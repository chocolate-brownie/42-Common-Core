/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:11:20 by mgodawat          #+#    #+#             */
/*   Updated: 2025/01/03 20:15:18 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->pix_ptr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}

static void	swap_buffers(t_fractal *fractal, int back_buffer)
{
	mlx_put_image_to_window(fractal->conn, fractal->win,
		fractal->img[back_buffer].img_ptr, 0, 0);
	fractal->curr_img = back_buffer;
}

int	render_frame(t_fractal *fractal)
{
	int	back_buffer;
	int	x;
	int	y;

	back_buffer = (fractal->curr_img + 1) % 2;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_pixel(&fractal->img[back_buffer], x, y, 0x00FF0000);
			x++;
		}
		y++;
	}
	swap_buffers(fractal, back_buffer);
	return (1);
}

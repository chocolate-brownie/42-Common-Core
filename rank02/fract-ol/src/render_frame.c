/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:11:20 by mgodawat          #+#    #+#             */
/*   Updated: 2025/01/04 19:57:23 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	put_pixel(t_img *img, int x, int y, int color)
{
	int	offset;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pix_ptr + offset) = color;
}

static void	map_coordinates(int x, int y, t_complex *c, t_fractal *fractal)
{
	fractal->param.unscaled_num = x;
	fractal->param.new_min = -2;
	fractal->param.new_max = +2;
	fractal->param.old_min = 0;
	fractal->param.old_max = WIDTH;
	c->x_real = map(fractal);
	fractal->param.unscaled_num = y;
	fractal->param.new_min = +2;
	fractal->param.new_max = -2;
	fractal->param.old_min = 0;
	fractal->param.old_max = HEIGHT;
	c->y_imaginary = map(fractal);
}

static int	map_colors(int i, t_fractal *fractal)
{
	fractal->param.unscaled_num = i;
	fractal->param.new_min = COLOR_BLACK;
	fractal->param.new_max = COLOR_WHITE;
	fractal->param.old_min = 0;
	fractal->param.old_max = fractal->max_iteration;
	return (int)map(fractal);
}

static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	double		magnitude_squared;
	int			i;
	int			color;

	i = 0;
	z.x_real = 0.0;
	z.y_imaginary = 0.0;
	map_coordinates(x, y, &c, fractal);
	while (i < fractal->max_iteration)
	{
		z = sum_complex(square_complex(z), c);
		magnitude_squared = z.x_real * z.x_real + z.y_imaginary * z.y_imaginary;
		if (magnitude_squared > fractal->escape_value)
		{
			color = map_colors(i, fractal);
			put_pixel(&fractal->img[fractal->curr_img], x, y, color);
			return ;
		}
		++i;
	}
	put_pixel(&fractal->img[fractal->curr_img], x, y, COLOR_WHITE);
}

void	render_frame(t_fractal *fractal)
{
	int	back_buffer;
	int	y;
	int	x;

	y = 0;
	printf("\nStarting new frame render...\n");
	back_buffer = (fractal->curr_img + 1) % 2;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			handle_pixel(x, y, fractal);
			x++;
		}
		y++;
	}
	printf("Frame complete, swapping buffers...\n");
	swap_buffers(fractal, back_buffer);
}

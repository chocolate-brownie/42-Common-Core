/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_buffers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:10:28 by mgodawat          #+#    #+#             */
/*   Updated: 2025/01/04 14:48:45y mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	init_image_buffers(t_fractal *fractal)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		fractal->img[i].img_ptr = mlx_new_image(fractal->conn, WIDTH, HEIGHT);

		fractal->img[i].pix_ptr = mlx_get_data_addr(fractal->img[i].img_ptr,
				&fractal->img[i].bpp, &fractal->img[i].line_len,
				&fractal->img[i].endian);
		i++;
	}
	fractal->curr_img = 0;
	return (1);
}

void	swap_buffers(t_fractal *fractal, int back_buffer)
{
	mlx_put_image_to_window(fractal->conn, fractal->win,
		fractal->img[back_buffer].img_ptr, 0, 0);
	fractal->curr_img = back_buffer;
}
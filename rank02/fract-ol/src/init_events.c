/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 03:51:26 by mgodawat          #+#    #+#             */
/*   Updated: 2025/01/03 20:22:50 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static int	destroy(t_fractal *fractal)
{
	mlx_destroy_image(fractal->conn, fractal->img[0].img_ptr);
	mlx_destroy_image(fractal->conn, fractal->img[1].img_ptr);
	mlx_destroy_window(fractal->conn, fractal->win);
	mlx_destroy_display(fractal->conn);
	free(fractal->conn);
	exit(0);
}

static int	key_hook(int keysym, t_fractal *fractal)
{
	// const double	move_factor = 0.1;
	if (!fractal)
		return (1);
	if (keysym == KEY_ESC)
		destroy(fractal);
	/* 	if (keysym == KEY_LEFT)
			fractal->math.shift_x += (move_factor * fractal->math.zoom);
		if (keysym == KEY_RIGHT)
			fractal->math.shift_x -= (move_factor * fractal->math.zoom);
		if (keysym == KEY_UP)
			fractal->math.shift_y -= (move_factor * fractal->math.zoom);
		if (keysym == KEY_DOWN)
			fractal->math.shift_y += (move_factor * fractal->math.zoom);
		if (keysym == KEY_PLUS && fractal->math.iterations < 500)
			fractal->math.iterations += 10;
		if (keysym == KEY_MINUS && fractal->math.iterations > 10)
			fractal->math.iterations -= 10;
		if (keysym == KEY_R)
			data_init(fractal); */
	// fractal_draw(fractal);
	return (0);
}

/* static void	handle_zoom(t_fractal *fractal, double factor, int x, int y)
{
	double			mouse_x;
	double			mouse_y;
	const double	zoom_in_factor = 1.1;
	const double	zoom_out_factor = 0.9;

	mouse_x = (x - WIDTH / 2.0) * fractal->math.zoom + fractal->math.shift_x;
	mouse_y = (y - HEIGHT / 2.0) * fractal->math.zoom + fractal->math.shift_y;
	fractal->math.zoom *= factor;
	fractal->math.shift_x = mouse_x - (mouse_x - fractal->math.shift_x)
		* factor;
	fractal->math.shift_y = mouse_y - (mouse_y - fractal->math.shift_y)
		* factor;
} */
/* static int	mouse_hook(int button, int x, int y, t_fractal *fractal)
{
	if (!fractal)
		return (1);
	if (button == MOUSE_WHEEL_UP)
		handle_zoom(fractal, zoom_in_factor, x, y);
	if (button == MOUSE_WHEEL_DOWN)
		handle_zoom(fractal, zoom_out_factor, x, y);
	// fractal_draw(fractal);
	return (0);
} */
void	init_events(t_fractal *fractal)
{
	if (!fractal || !fractal->win)
		return ;
	mlx_key_hook(fractal->win, key_hook, fractal);
	// mlx_mouse_hook(fractal->win, mouse_hook, fractal);
	mlx_hook(fractal->win, DESTROY_NOTIFY, 0, destroy, fractal);
}

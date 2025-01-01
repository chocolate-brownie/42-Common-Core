/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 18:47:52 by mgodawat          #+#    #+#             */
/*   Updated: 2025/01/01 19:16:59 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

static int	close_window(t_fractol *f)
{
	clean_exit(f, NULL, 0);
	return (0);
}

static int	key_handler(int keycode, t_fractol *f)
{
	if (keycode == ESC)
		close_window(f);
	return (0);
}

static int	mouse_handler(int button, int x, int y, t_fractol *f)
{
	return (0);
}

void	setup_hooks(t_fractol *fractol)
{
	mlx_hook(fractol->window, KEY_PRESS, 1L << 0, key_handler, fractol);
	mlx_hook(fractol->window, BUTTON_PRESS, 1L << 0, close_window, fractol);
	mlx_hook(fractol->window, BUTTON_PRESS, 1L << 0, mouse_handler, fractol);
}

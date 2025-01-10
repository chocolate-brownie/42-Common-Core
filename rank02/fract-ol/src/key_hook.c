/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 03:32:35 by mgodawat          #+#    #+#             */
/*   Updated: 2025/01/07 10:12:26 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	reset_fractal(t_fractal *fractal)
{
	if (fractal->fractal_type == 4)
	{
		fractal->center_x = -0.5;
		fractal->center_y = 0.0;
		fractal->zoom_level = 3.0 / SIZE_W;
	}
	else if (fractal->fractal_type == 2)
		process_julia(fractal);
	fractal->center_x = 0.0;
	fractal->center_y = 0.0;
	fractal->zoom_level = 4.0 / SIZE_W;
	fractal->max_iterations = 42;
	fractal->palette_number = 1;
}

void	print_manual(void)
{
	ft_printf("\n╔═══════════ MGODAWAT FRACTOL MANUAL ═════════════╗\n");
	ft_printf("║                                                 ║\n");
	ft_printf("║  Navigation Controls:                           ║\n");
	ft_printf("║  • WASD or Arrow Keys : Move around             ║\n");
	ft_printf("║  • Mouse Wheel        : Zoom in/out             ║\n");
	ft_printf("║  • R Key              : Reset to default        ║\n");
	ft_printf("║                                                 ║\n");
	ft_printf("║  Detail Controls:                               ║\n");
	ft_printf("║  • +/- Keys          : Adjust iterations        ║\n");
	ft_printf("║                                                 ║\n");
	ft_printf("║  Colorscheme:                                   ║\n");
	ft_printf("║  • F1                : Hellfire                 ║\n");
	ft_printf("║  • F2                : Classic                  ║\n");
	ft_printf("║  • F3                : Rainbow                  ║\n");
	ft_printf("║                                                 ║\n");
	ft_printf("║  Other Controls:                                ║\n");
	ft_printf("║  • ESC               : Exit program             ║\n");
	ft_printf("║  • H Key             : Show this manual         ║\n");
	ft_printf("║                                                 ║\n");
	ft_printf("╚═════════════════════════════════════════════════╝\n\n");
}

int	key_hook(int keycode, t_fractal *vars)
{
	if (keycode == KEY_ESC)
		destroy(vars);
	else if (keycode == 'a' || keycode == KEY_LEFT)
		vars->center_x = vars->center_x - STEP * vars->zoom_level;
	else if (keycode == 'd' || keycode == KEY_RIGHT)
		vars->center_x = vars->center_x + STEP * vars->zoom_level;
	else if (keycode == 'w' || keycode == KEY_UP)
		vars->center_y = vars->center_y - STEP * vars->zoom_level;
	else if (keycode == 's' || keycode == KEY_DOWN)
		vars->center_y = vars->center_y + STEP * vars->zoom_level;
	else if (keycode == KEY_PLUS || keycode == KEY_NUM_PLUS)
		vars->max_iterations += 2;
	else if (keycode == KEY_MINUS || keycode == KEY_NUM_MINUS)
		vars->max_iterations -= 2;
	else if (keycode == KEY_F1)
		vars->palette_number = 1;
	else if (keycode == KEY_F2)
		vars->palette_number = 2;
	else if (keycode == KEY_F3)
		vars->palette_number = 3;
	else if (keycode == 'r')
		reset_fractal(vars);
	else if (keycode == 'h')
		print_manual();
	return (0);
}

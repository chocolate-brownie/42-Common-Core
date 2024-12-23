/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:11:50 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/23 16:17:44 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

static int	esc_close(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx_conn, vars->mlx_win);
		mlx_destroy_display(vars->mlx_conn);
		free(vars->mlx_conn);
		free(vars);
		exit(0);
	}
	return (0);
}

static int	mouse_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx_conn, vars->mlx_win);
	mlx_destroy_display(vars->mlx_conn);
	free(vars->mlx_conn);
	free(vars);
	exit(0);
}
void	close_window(t_vars *vars)
{
	mlx_hook(vars->mlx_win, KEY_PRESS, 1L << 0, esc_close, vars);
	mlx_hook(vars->mlx_win, DESTROY_NOTIFY, 0, mouse_close, vars);
	mlx_loop(vars->mlx_conn);
}

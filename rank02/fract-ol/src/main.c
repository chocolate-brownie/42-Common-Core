/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:58:10 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/23 15:12:17 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	close(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx_conn, vars->mlx_win);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_vars	*vars;

	(void)argc;
	vars->mlx_conn = mlx_init();
	vars->mlx_win = mlx_new_window(vars->mlx_conn, WIDTH, HEIGHT, argv[1]);
	mlx_hook(vars->mlx_win, 2, 1L << 0, close, &vars);
	return (0);
}

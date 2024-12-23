/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:55:22 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/23 16:11:26 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

t_vars	*open_window(char *program_name)
{
	t_vars	*vars;

	vars = NULL;
	vars = malloc(sizeof(t_vars));
	if (!vars)
		return (NULL);
	vars->mlx_conn = mlx_init();
	if (!vars->mlx_conn)
	{
		free(vars);
		return (NULL);
	}
	vars->mlx_win = mlx_new_window(vars->mlx_conn, WIDTH, HEIGHT, program_name);
	if (!vars->mlx_win)
	{
		mlx_destroy_display(vars->mlx_conn);
		free(vars->mlx_conn);
		free(vars);
		return (NULL);
	}
	return (vars);
}
